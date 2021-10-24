/**
 * @file Detection.cpp
 * @brief Detecting humans present in the video with class definition
 * @author Advait Patole
 * @author Gaurav Raut
 *
 * Copyright (c) 2021 Advait Patole, Gaurav Raut
 *
 * MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <vector>
#include <string>
#include <iostream>
#include <Detection.hpp>
#include "Box.h"
#include <Human.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>

Detection :: Detection() {
  confidences = {};
  Boxes = {};
  indices = {};
  detections = {};
  humans = 0;
  storage = {{0, 0, 0}};
}

void Detection :: humandetection(cv::Mat frame) {
  try {
    // Set SVM pretrained model for human detection
    hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());

    // Set SVM model parameters like
    // foundLocations, foundWeights, winStride for human detection
    hog.detectMultiScale(frame, Boxes, confidences, 0,
                         cv::Size(4, 4), cv::Size(16, 16), 1.2, 1.02);
  }
  catch(...) {
    std::cout << "Caught exception in humandetection function" << std::endl;
  }
}

void Detection :: nms() {
  try {
    // Setting nms_threshold and score_threshold for NMS
    double nms_threshold = 0.7;
    double confidence_threshold = 0.7;

    // Converting the dataype to float
    std::vector<float> scores(confidences.begin(), confidences.end());

    // Apply non-maximum suppression procedure.
    cv::dnn::NMSBoxes(Boxes, scores,
                      confidence_threshold, nms_threshold, indices);
    std::cout << "Count of Boxes before"
        " Non-Max Suppression " << Boxes.size() << std::endl;
  }
  catch(...) {
      std::cout << "Caught exception in nms function" << std::endl;
    }
}

void Detection :: drawboxes(cv::Mat frame) {
  try {
    // Iterate over the updated detections after nms to draw rectangle
    std::cout << "Count of Boxes after Non-Max"
        " Suppression " << indices.size() << std::endl;
    std::vector<double> human_coordinates;
    detections.clear();
    for (int index : indices) {
      std::cout << "Box detected after"
          " Non Max Suppression at index " << index << std::endl;
      cv::Rect box = Boxes[index];
      int start_x, start_y, end_x, end_y;
      start_x = box.x;
      start_y = box.y;
      end_x = box.x + box.width;
      end_y = box.y + box.height;

      // filling each box as Box object
      Box* bbox = new Box(start_x, start_y, end_x, end_y, box);
      detections.push_back(bbox);

      // Applying transformations camera frame to robot frame
      Human hum;
      hum.calc_centre(bbox);

      // Getting transformed human coordinates in mm
      human_coordinates = hum.transformation(frame);

      std::cout << "Start positions are " << start_x
          << " " << start_y << std::endl;
      std::cout << "End positions are " << end_x << " " << end_y << std::endl;

      // Top Left corner of bounding box
      cv::Point pt1(start_x, start_y);

      // Bottom Right corner of bounding box
      cv::Point pt2(end_x, end_y);

      // Draw corresponding rectangle with green color
      cv::rectangle(frame, pt1, pt2, cv::Scalar(0, 255, 0));
      std::string text = "(" + std::to_string(human_coordinates[0])
          + "," + std::to_string(human_coordinates[1]) +
          "," + std::to_string(human_coordinates[2]) + ")";

      // Writing the coordinates in mm
      cv::putText(frame, text, cv::Point(start_x, start_y),
                  cv::FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(255, 0, 0), 2);
    }
  }
  catch(...) {
      std::cout << "Caught exception in drawboxes function" << std::endl;
    }
}

bool Detection::is_same(int x[2], int y[2]) {
  try {
    if (x[0] - y[0] < 2 && x[1] - y[1] < 2) {return true;}
    else {
      return false;
    }
  }
  catch(...) {
    std::cout << "\n Error in is_same";
  }
}

void Detection::track(cv::Mat img) {
    try {
      std::cout << "Starting tracker\n";
      if (!indices.empty()) {
        std::cout << "indices not empty works\n";
        // Condition 1: Check if storage is empty
       if (storage.empty()) {
          std::cout << "storage empty works\n";
          for (auto i = 0 ; i < detections.size(); i++) {
            Human sam;
            sam.calc_centre(detections[i]);
            std::cout << "Centre" <<
                sam.centre[0] << "," << sam.centre[1] << "\n";
            std::vector<int> psh = {i, sam.centre[0], sam.centre[1]};
            storage.push_back(psh);
          }
        }
       else {
         for (auto j = 0 ; j < detections.size(); j++) {
             Human sam;
             sam.calc_centre(detections[j]);
             auto temp = storage;
             storage.clear();
             for (auto i : temp) {
               int tem[2] = {i[1] , i[2]};
               if (is_same(sam.centre,tem)) {
                 std::vector<int> psh = {j, sam.centre[0], sam.centre[1]};
                 storage.push_back(psh);
               }
             }
           }
         }
        for (auto o : storage) {
          std::string text = "ID " + std::to_string(o[0]);
          cv::putText(img, text, cv::Point(o[1],o[2]), cv::FONT_HERSHEY_DUPLEX, 1.0, CV_RGB(0, 255, 0), 2);
        }
      }
      else {
        storage.clear();
        std::cout << "Condition not satisfied\n";
      }
    }
    catch(...) {
      std::cout << "\nError in track function";
    }
}

