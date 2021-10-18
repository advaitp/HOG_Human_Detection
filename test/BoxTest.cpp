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


TEST(BoxTest1, testBoxdefault_constructor) {
  Box test();
  ASSERT_EQ(test.box.width(), 0);
}

TEST(BoxTest2, testBoxconfidence_constructor) {
  Box test(1, 1, 1, 1, 0.7);
  ASSERT_EQ(test.confidence, 0.7);
}

TEST(BoxTest2, testBoxcoordinate_constructor) {
  Box test(100, 250, 600, 950);
  ASSERT_EQ(test.box.width(), 500);
}
