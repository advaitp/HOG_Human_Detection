///============================================================================
/// @file        : Box.cpp
/// @author      : gauraut (Driver)
/// @author      : Advait Patole (Navigator)
/// @version     : 1.0.1
/// @copyright   : MIT License
/// @brief       : Box class definition
///============================================================================

#include "Box.h"

Box::Box(const int x1, const int y1, const int x2, const int y2) {
  coordinates[0] = x1;
  coordinates[1] = y1;
  coordinates[2] = x2;
  coordinates[3] = y2;
  box.x = x1;
  box.y = y1;
  box.width = x2 - x1;
  box.height = y2 - y1;
  confidence = 1;
}

Box::Box(const int x1, const int y1, const int x2, const int y2, const double confi) {
  coordinates[0] = x1;
  coordinates[1] = y1;
  coordinates[2] = x2;
  coordinates[3] = y2;
  box.x = x1;
  box.y = y1;
  box.width = x2 - x1;
  box.height = y2 - y1;
  confidence = confi;
}

Box::Box() {
  coordinates[0] = 0;
  coordinates[1] = 0;
  coordinates[2] = 0;
  coordinates[3] = 0;
  box.x = 0;
  box.y = 0;
  box.width = 0;
  box.height = 0;
  confidence = 1;
}
