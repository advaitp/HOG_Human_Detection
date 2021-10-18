///============================================================================
/// @file        : BoxTest.cpp
/// @author      : gauraut (Driver)
/// @author      : Advait Patole (Navigator)
/// @version     : 1.0.1
/// @copyright   : MIT License
/// @brief       : BoxTest.cpp test file
///============================================================================

#include <gtest/gtest.h>
#include "Box.h"

TEST(boxdummy, boxshould_pass) {
  EXPECT_EQ(1, 1);
}
/*
TEST(BoxTest1, testBoxdefault_constructor) {
  Box test;
  ASSERT_EQ(test.box.width, 0);
}

TEST(BoxTest2, testBoxconfidence_constructor) {
  int x = 1;
  double y = 0.7;
  Box test(x, x, x, x, y);
  ASSERT_EQ(test.confidence, 0.7);
}

TEST(BoxTest2, testBoxcoordinate_constructor) {
  int x1 = 100 , y1 = 250, x2 = 600, y2 = 950;
  Box test(x1, y1, x2, y2);
  ASSERT_EQ(test.box.width, 500);
}
*/
