///============================================================================
/// @file        : main.cpp
/// @author      : gauraut (Driver)
/// @author      : Advait Patole (Navigator)
/// @version     : 1.0.1
/// @copyright   : MIT License
/// @brief       : main.cpp Main function to run our demo
///============================================================================

#include <iostream>
#include "Box.h"
#include"Human.h"
#include <Camera.hpp>
#include <Detection.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

/// @fn int main()
/// @brief This is our main function to run a demo for our API
///
/// @pre
/// @post
/// @return
int main() {
  Camera cam(0);
  cv::Mat cap, cap_gray;
  Detection human_detection_demo;
  std::cout << "Start detection using camera" << std::endl;

  // Name of camera frame
  std::string window_name = "My Camera";

  while (1) {
    // stores current frame in webcam.frame
    cam.capturevideo();

    // Current frame of camera
    cap = cam.frame;

    // Convert to grayscale image
    cv::cvtColor(cap, cap_gray, cv::COLOR_BGR2GRAY);

    // Detection of human in frame
    human_detection_demo.humandetection(cap_gray);

    // Applying Non Max Suppression on camera frame
    human_detection_demo.nms();

    // Draw Bounding boxes around human
    human_detection_demo.drawboxes(cap);

    // Track and identify humans
    human_detection_demo.track(cap);

    // show the frame in the created window
    cv::imshow(window_name, cap);

    if (cv::waitKey(10) == 27) {
        std::cout << "Esc key is pressed "
            "by user. Stopping the video" << std::endl;
        break;
     }
  }
  return 0;
}
