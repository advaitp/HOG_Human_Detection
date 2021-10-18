///============================================================================
/// @file        : HumanTest.cpp
/// @author      : gauraut (Driver)
/// @author      : Advait Patole (Navigator)
/// @version     : 1.0.1
/// @copyright   : MIT License
/// @brief       : HumanTest.cpp include file
///============================================================================

#include <gtest/gtest.h>
#include "Human.h"

TEST(HumanTest1, testHumancalc_centre) {
  Human test;
  test.coordinates(0, 0, 30, 40, 10);
  EXPECT_EQ(test.centre[0], 15);
  EXPECT_EQ(test.centre[1], 20);
}

TEST(HumanTest2, testHumantransformation) {
  Human test;
  test.coordinates(20,20,80,110);
}
