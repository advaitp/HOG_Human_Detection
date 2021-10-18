///============================================================================
/// @file        : HumanTest.cpp
/// @author      : gauraut (Driver)
/// @author      : Advait Patole (Navigator)
/// @version     : 1.0.1
/// @copyright   : MIT License
/// @brief       : HumanTest.cpp test file
///============================================================================

#include <gtest/gtest.h>
#include "Human.h"

TEST(humandummy, humanshould_pass) {
  EXPECT_EQ(1, 1);
}
//TEST(HumanTest1, testHumancalc_centre) {
//  Human test;
//  test.coordinates[0] = 0;
//  test.coordinates[1] = 0;
//  test.coordinates[2] = 30;
//  test.coordinates[3] = 40;
//  EXPECT_EQ(test.centre[0], 15);
//  EXPECT_EQ(test.centre[1], 20);
//}

/*TEST(HumanTest2, testHumantransformation) {
  Human test;
  test.coordinates(20,20,80,110);
}*/
