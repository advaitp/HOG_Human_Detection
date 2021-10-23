///============================================================================
/// @file        : Box.cpp
/// @author      : gauraut (Driver)
/// @author      : Advait Patole (Navigator)
/// @version     : 1.0.1
/// @copyright   : MIT License
/// @brief       : Box class definition
///============================================================================

#include "Box.h"

Box::Box(const int x1, const int y1, const int x2, const int y2, cv::Rect Box) {
  coordinates[0] = x1;
  coordinates[1] = y1;
  coordinates[2] = x2;
  coordinates[3] = y2;
  bbox = Box;
}

Box::Box() {
  coordinates[0] = 0;
  coordinates[1] = 0;
  coordinates[2] = 0;
  coordinates[3] = 0;
  cv::Rect bbox(0, 0, 0, 0);
}
