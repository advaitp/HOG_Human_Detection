///============================================================================
/// @file        : Human.cpp
/// @author      : gauraut (Driver)
/// @author      : Advait Patole (Navigator)
/// @version     : 1.0.1
/// @copyright   : MIT License
/// @brief       : Human class definition
///============================================================================

#include "Human.h"

Human::Human() {
  coordinates[0] = 0;
  coordinates[1] = 0;
  coordinates[2] = 30;
  coordinates[3] = 40;
}

void Human::calc_centre(const Box in) {
  centre[0] = in.box.x+(in.box.width/2);
  centre[1] = in.box.y+(in.box.height/2);
}
/*
void transormation(const Box &box) {

}*/
