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
#include <iostream>
#include<Detection.hpp>
#include<Box.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>

void Detection :: humandetection(cv::Mat frame) {
  /// Set SVM pretrained model for human detection
  hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());

  /// variable that stores the weight of each bounding box


  /// Set SVM model parameters like foundLocations, foundWeights, winStride for human detection
  hog.detectMultiScale(frame, confidences, Boxes, 0, Size(2,2), Size(10,10), 1.2, 1.02);

  /// Iterate over the collection of bounding boxes
  for(size_t i = 0; i < found.size(); i++ ){
       cv::Rect r = found[i];
       int start_x, start_y, end_x, end_y;

       start_x = found[i].x;
       start_y = found[i].y;
       end_x = found[i].x + found[i].width;
       end_y = found[i].y + found[i].height;

       Box bbox = new Box(start_x, start_y, end_x, end_y) ;

       detections.push_back(bbox);
    }
}

void Detection :: nms() {
  // Apply non-maximum suppression procedure.
  std::vector<int> indices;
  double nms_threshold = 0.7;
  double confidence_threshold = 0.6;
  NMSBoxes(Boxes, confidences, confidence_threshold, nms_threshold, indices);
}

void Detection :: drawboxes(cv::Mat frame) {
  /// Iterate over the updated detections after nms to draw rectangle
  for(Box bbox : detections){
    int start_x, start_y, end_x, end_y ;
    start_x = bbox[0];
    start_y = bbox[1];
    end_x = bbox[2];
    end_y = bbox[3];

    /// Top Left corner of bounding box
    cv::Point pt1(start_x, start_y);

    /// Bottom Right corner of bounding box
    cv::Point pt2(end_x, end_y);

    /// Draw corresponding rectangle with green color
    cv::rectangle(frame, pt1, pt2, cv::Scalar(0, 255, 0));
  }
}
