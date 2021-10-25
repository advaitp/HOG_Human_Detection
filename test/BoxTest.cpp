///============================================================================
/// @file        : BoxTest.cpp
/// @author      : gauraut (Driver)
/// @author      : Advait Patole (Navigator)
/// @version     : 2.0.1
/// @copyright   : MIT License
/// @brief       : BoxTest.cpp test file
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

TEST(BoxTest1, testboxparameterconstructor) {
  cv::Rect ibox(0, 0, 100, 180);
  Box* box = new Box(0, 0, 100, 180, ibox);
  EXPECT_EQ(box->coordinates[0], 0);
  EXPECT_EQ(box->coordinates[1], 0);
  EXPECT_EQ(box->coordinates[2], 100);
  EXPECT_EQ(box->coordinates[3], 180);
}

TEST(BoxTest2, testboxconstructor) {
  Box* box = new Box();
  EXPECT_EQ(box->coordinates[0], 0);
  EXPECT_EQ(box->coordinates[1], 0);
  EXPECT_EQ(box->coordinates[2], 0);
  EXPECT_EQ(box->coordinates[3], 0);
}


