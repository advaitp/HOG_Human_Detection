///============================================================================
/// @file        : Box.cpp
/// @author      : gauraut (Driver)
/// @author      : Advait Patole (Navigator)
/// @version     : 1.0.1
/// @copyright   : MIT License
/// @brief       : Box class definition
///============================================================================

#include "Box.h"

Box::Box(int &x1, int &y1, int &x2, int &y2) {
  coordinates = {x1, y1, x2, y2};
  box(x1, y1, (x2-x1), (y2-y1));
}

Box::Box() {
  coordinates = {0, 0, 0, 0};
  box(0, 0, 0, 0);
}
