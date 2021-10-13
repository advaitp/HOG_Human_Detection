//============================================================================
// Name        : Sample_OpenCV.cpp
// Author      : Gaurav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
  VideoCapture webcam(0); //Video Input variable
  
  Mat ipstream;
  //ipstream.read("ped.jpeg");
  //int str = 0;

  while (1) {
    webcam.read(ipstream);
    //resize(ipstream, ipstream, Size(64, 128));
    cv::HOGDescriptor acme_human_engine;
    acme_human_engine.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());
    vector<Rect> detections;
    //vector<double> weights;
    acme_human_engine.detectMultiScale(ipstream, detections, 0, Size(2,2), Size(10,10), 1.2, 1.02);
    
    for (auto& i : detections) {
    rectangle(ipstream, i.tl(), i.br(), Scalar(255, 0, 0), 2);
    }
    imshow("Acme_Human_Detection_Engine", ipstream);
    waitKey(2);
  }
return 0;
}
