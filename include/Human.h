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
#include <vector>
#include <Eigen/Geometry>
#include <Eigen/Dense>
#include <Eigen/Core>

class Human{
 private:
  /// Average height of human
  int height;

  /// Dots per inches(DPI) of device
  int DPI;

  /// Camera Viewing angle
  int angle;

 public:
  Human();

  // Centre of gravity of human
  int centre[2];

  /// @fn double pixel_to_mm(int pixel)
  /// @brief Function to convert pixel values to mm
  ///
  /// @pre
  /// @post
  /// @param pixel
  /// @return coordinates in mm
  double pixel_to_mm(int pixel);

  /// @fn double get_distance(double z_coord)
  /// @brief Function to get the x distance of human from robot
  ///
  /// @pre
  /// @post
  /// @param z_coord
  /// @return distance in mm
  double get_distance(double z_coord);

  /// @fn void calc_centre(Box* bbox)
  /// @brief This function will calculate the CoG (int centre[2])
  /// coordinates of the human in camera frame
  ///
  /// @pre
  /// @post
  /// @param
  void calc_centre(Box* bbox);

  /// @fn void transformation(cv::Mat frame)
  /// @brief This function will transform the co-ordinates
  /// of the human in robot reference frame
  ///
  /// @pre
  /// @post
  /// @param frame
  /// @return vector of coordinates
  std::vector<double> transformation(cv::Mat frame);
};

#endif  // INCLUDE_HUMAN_H_
