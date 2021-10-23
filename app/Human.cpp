///============================================================================
/// @file        : Human.cpp
/// @author      : gauraut (Driver)
/// @author      : Advait Patole (Navigator)
/// @version     : 1.0.1
/// @copyright   : MIT License
/// @brief       : Human class definition
///============================================================================

#include <Human.h>
#include <vector>
#include <Eigen/Geometry>
#include <Eigen/Dense>
#include <Eigen/Core>

Human::Human() {
  // Average height of human in mm
  height = 1728;
  DPI = 141;
  centre[0] = 0;
  centre[1] = 0;
}

void Human::calc_centre(Box* box) {
  centre[0] = box->bbox.x+(box->bbox.width/2);
  centre[1] = box->bbox.y+(box->bbox.height/2);
}

double Human::pixel_to_mm(int pixel){
  return (pixel * 25.4 ) / DPI;
}

std::vector<double> Human::transformation(cv::Mat frame) {
  try{
    int height, width;
    double xmm, ymm, zmm;
    Eigen::Matrix3d R;
    Eigen::VectorXd T(3, 1);
    Eigen::VectorXd Coord(4, 1);
    Eigen::VectorXd Transform(4, 1);
    Eigen::Matrix4d Trans;

    height = frame.size[0];
    width = frame.size[1];

    R = Eigen::Matrix3d::Identity();

    T(1,0) = width/2;
    T(2,0) = height/2;
    T(0,0) = 0;

    Trans.setIdentity();
    Trans.block<3,3>(0,0) = R;
    Trans.block<3,1>(0,3) = T;

    Coord(0,0) = 0;
    Coord(1,0) = centre[0];
    Coord(2,0) = centre[1];
    Coord(3,0) = 1;

    std::cout<<"Initial X coord : "<<Coord(0,0)<<std::endl;
    std::cout<<"Initial Y coord : "<<Coord(1,0)<<std::endl;
    std::cout<<"Initial Z coord : "<<Coord(2,0)<<std::endl;

    Transform = Trans*Coord;
    std::cout<<"Transformed X coord : "<<Transform(0,0)<<std::endl;
    std::cout<<"Transformed Y coord : "<<Transform(1,0)<<std::endl;
    std::cout<<"Transformed Z coord : "<<Transform(2,0)<<std::endl;

    xmm = static_cast<double>(pixel_to_mm(Transform(0,0)));
    ymm = static_cast<double>(pixel_to_mm(Transform(1,0)));
    zmm = static_cast<double>(pixel_to_mm(Transform(2,0)));

    return {xmm, ymm, zmm};
  }
  catch(...){
        std::cout << "Caught exception in transformation function"<<std::endl;
        return {0.0, 0.0, 0.0};
      }


}
