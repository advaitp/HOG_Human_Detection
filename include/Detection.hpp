/**
 * @file Detection.hpp
 * @brief Detecting humans present in the video
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

#ifndef INCLUDE_DETECTION_HPP_
#define INCLUDE_DETECTION_HPP_

#include <iostream>
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <Box.h>

class Detection{
 private :
  /// variable to access HOG descriptor
  cv::HOGDescriptor hog;

  /// Store collection of boxes
  vector<cv::Rect> Boxes ;

 public :
  /// variable to hold the all the bounding boxes after detection
  std::vector<Box> detections;

 /**
  * @brief Function to get all the detection boxes after detection using HOG and SVM
  * @param frame cv::Mat
  */
  void humandetection(cv::Mat frame);

 /**
  * @brief Function to overlapping bounding boxes
  *
  */
  void nms();

  /**
   * @brief Function to draw boundary around human
   *
   */
  void drawboxes(cv::Mat frame);
};

#endif  // INCLUDE_DETECTION_HPP_
