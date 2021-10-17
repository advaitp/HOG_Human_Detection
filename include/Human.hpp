/**
 * @file Human.hpp
 * @brief Class to store properties of bounding box containing humans
 * @author Advait Patole
 * @author Gaurav Raut
 *
 * Copyright (c) 2021 Advait Patole, Gaurav Raut
 *
 * MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef INCLUDE_HUMAN_HPP_
#define INCLUDE_HUMAN_HPP_

#include <iostream>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <Box.hpp>

class Human : public Box
{
  public :
  /// variable to hold center point of bounding box
  int center[2] ;

  /**
   * @brief Function to calculate center of bounding box
   *
   */
  void calc_center();

  /**
   * @brief Function to transform robot coordinates to world coordinates
   *
   */
  void transformation() ;

};

#endif  /* INCLUDE_HUMAN_HPP_ */
