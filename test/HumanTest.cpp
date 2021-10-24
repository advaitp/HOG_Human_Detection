///============================================================================
/// @file        : HumanTest.cpp
/// @author      : gauraut (Driver)
/// @author      : Advait Patole (Navigator)
/// @version     : 1.0.1
/// @copyright   : MIT License
/// @brief       : HumanTest.cpp test file
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

TEST(humandummy, humanshould_pass) {
  EXPECT_EQ(1, 1);
}

TEST(HumanTest1, testHumancalc_centre) {
  Human htest;
  cv::Rect box(0,0,100,160);
  Box* hbox = new Box(0, 0, 100, 160, box);

  htest.calc_centre(hbox);
  EXPECT_EQ(htest.centre[0], 50);
  EXPECT_EQ(htest.centre[1], 80);
}

TEST(HumanTest2, testpixel_to_mm) {
  Human htest;
  EXPECT_DOUBLE_EQ(htest.pixel_to_mm(282), 50.8);
}
