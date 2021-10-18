///============================================================================
/// @file        : Box.h
/// @author      : gauraut (Driver)
/// @author      : Advait Patole (Navigator)
/// @version     : 1.0.1
/// @copyright   : MIT License
/// @brief       : Box.h include file
///============================================================================

#ifndef INCLUDE_BOX_H_
#define INCLUDE_BOX_H_

#include <opencv2/opencv.hpp>

/// @class Box
/// @brief This is a Box class which will be used to draw
/// boxes around the detected human
///
class Box {
 public:
  Box(int* x1, int* y1, int* x2, int* y2, double* confidence);
  // variable initialization constructor
  Box();  // default constructor
  int coordinates[4];  // The four co-ordinates will show the upper
  // left and lower right  and y coordinates [x1, y1, x2, y2]

  cv::Rect box;  // Will inherit attributes from cv::Rect
};

#endif  // INCLUDE_BOX_H_
