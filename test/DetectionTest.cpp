///============================================================================
/// @file        : DetectionTest.cpp
/// @author      : gauraut (Driver)
/// @author      : Advait Patole (Navigator)
/// @version     : 2.0
/// @copyright   : MIT License
/// @brief       : DetectionTest.cpp test file
///============================================================================

#include <gtest/gtest.h>
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

TEST(DetectionTest1, testDetectionconstructor) {
  Detection sample;
  std::vector<int> initialise = {0,0,0};
  EXPECT_EQ(initialise, sample.storage[0]);
}

TEST(DetectionTest2, testDetection_humandetection) {
  Detection sample;
  cv::Mat img;
  img = cv::imread("/black.jpg");
  sample.humandetection(img);
  EXPECT_EQ(true,sample.Boxes.empty());
}

TEST(DetectionTest3, testDetection_nms) {
  Detection sample;
  cv::Mat img;
  img = cv::imread("/black.jpg");
  sample.humandetection(img);
  sample.nms();
  EXPECT_EQ(true,sample.indices.empty());
}

TEST(DetectionTest4, testDetection_drawboxes) {
  Detection sample;
  cv::Mat img;
  img = cv::imread("/black.jpg");
  sample.humandetection(img);
  sample.nms();
  sample.drawboxes(img);
  EXPECT_EQ(true,sample.detections.empty());
}

TEST(DetectionTest5, testDetection_is_same) {
  Detection sample;
  int arr1[2] = {100,100};
  int arr2[2] = {101,101};
  bool op = sample.is_same(arr1,arr2);
  ASSERT_EQ(true,op);
}

TEST(DetectionTest6, testDetection_track) {
  Detection sample;
  cv::Mat img;
  img = cv::imread("/black.jpg");
  sample.humandetection(img);
  sample.nms();
  sample.drawboxes(img);
  sample.track(img);
  ASSERT_EQ(true,sample.storage.empty());
}
