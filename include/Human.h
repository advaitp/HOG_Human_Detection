///============================================================================
/// @file        : Human.h
/// @author      : gauraut (Driver)
/// @author      : Advait Patole (Navigator)
/// @version     : 1.0.1
/// @copyright   : MIT License
/// @brief       : Human.h include file
///============================================================================

#ifndef INCLUDE_HUMAN_H_
#define INCLUDE_HUMAN_H_

#include "Box.h"

class Human: public Box {
 public:

  Human();
  int centre[2];  // This array will store the x and y coordinates
  // of the Human CoG in camera frame

  /// @fn void calc_centre(Box&)
  /// @brief This function will calculate the CoG (int centre[2])
  /// coordinates of the human in camera frame
  ///
  /// @pre
  /// @post
  /// @param
  void calc_centre(const Box);
  /// @fn void transformation(Box&)
  /// @brief This function will transform the co-ordinates
  /// of the human in robot reference frame
  ///
  /// @pre
  /// @post
  /// @param
  void transormation(Box);
};

#endif  // INCLUDE_HUMAN_H_
