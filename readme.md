# HOG_Human_Detection
## Project Contributors
- Gaurav Raut - M.Eng. Robotics student. I like to make puns.
- Advait Patole - Graduate student at University of Maryland pursuing M.Eng. Robotics. Likes rock music.
# Build Status Coverage Status
[![Build Status](https://app.travis-ci.com/gauraut/HOG_Human_Detection.svg?branch=main)](https://app.travis-ci.com/gauraut/HOG_Human_Detection)
[![Coverage Status](https://coveralls.io/repos/github/gauraut/HOG_Human_Detection/badge.svg?branch=main)](https://coveralls.io/github/gauraut/HOG_Human_Detection?branch=main)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
## License
MIT License

Copyright (c) 2021 Gaurav Raut, Advait Patole

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

## Planning and management documents

- Product and Iteration backlogs, Work logs - https://docs.google.com/spreadsheets/d/1AqmzROpvQzZs42nM-5xIrxISOKAmEnqSZvvMMRmAUtc/edit?usp=sharing
- Sprint Document - https://docs.google.com/document/d/148LJN0tJzzBdqmiuJV0zaLxc1Qg-1pK8uLO6xgxRnHk/edit?usp=sharing
- Gantt Chart(Timeline) - https://docs.google.com/spreadsheets/d/111fKcOGjVEq8wXLX9FNTWaAUSNsgvVnWToeZoKKRCYU/edit?usp=sharing

## Overview

Our design uses monocular camera to detect humans and get their positions in the robot’s reference frame. The module is developed in such a way that it detects humans (N>=1) and then creates bounding box around it. The distance of human is calculated from the pixel values of the bounding boxes. This system is perfect for use in robots like autonomous caddies in malls or airports for transportation which is under-development by Acme. The module detects humans and if the distance is below a threshold, the vehicle slows down. The distance measurements can be fed to the odometry of the robot in order to control its motion. The project could be easily expanded and trained to detect more objects and take actions based on the type of the object. The AIP design process allows continuous development. Because of this, new features and modules could be added over new sprints and thus making the module highly customizable.
## Algorithm

The HOG descriptors convert image into a feature vector. The input image (641283) is converted to a 3780-length vector. The SVM classifier is trained by fitting appropriate parameters to train whether image has human or not. Once it is trained, a sliding window is created of size 64*128 which creates different image patches each of length 3780 feature vector. The SVM is used on each of the feature vector to get whether human is found in that image or not. If it is found, then we store the coordinates to create the bounding boxes. In-order to solve the problem of multiple bounding boxes, we can use a non max suppression to remove overlapping boxes.
![image](https://learnopencv.com/wp-content/uploads/2016/12/hog-cell-gradients-768x432.png)
## Technology

The monocular camera inputs a stream of images, i.e., video, to our microprocessor. Every frame in the image will be converted into a feature vector by our custom-made HOG feature descriptor. The feature vector will be given as an input to our pre-trained custom-made linear SVM which will classify the features as Human and Non-Human. Further, if there is a human in the frame, the algorithm will calculate the distance of the human from the caddy based on the pixel location and pre-defined equations and assumptions.
![Technology](https://user-images.githubusercontent.com/77606010/137650666-c4d7e0d4-4021-4aa9-a76d-2000d07be1b2.png)

## Risks and Mitigation: 
 
A  HOG  is  not  a  rotation  invariant  representation.  This  means 
that  HOG  can  only  vectorize  features  of  images  within  a 
certain orientation range for object detection assignment. This 
can be corrected if we train images with different orientation. 
Monocular camera we have made calibration before 
implementing  while  comparing  the  given  distance  with  the 
calibrated  calculations  instead  we  can  use  depth  cameras  for 
more  accurate  results  like  Intel®  RealSense™ depth camera 
D435. 
HOG is not scale invariant we need to normalize the data to a 
particular scale to overcome this. 
Multiple  detection  boxes  get  created  during  detection  we  can 
use non max suppression to solve that problem.

## Standard install via command-line
```
git clone --recursive https://github.com/dpiet/cpp-boilerplate
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage (for assignments beginning in Week 4)
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
## Making Doxygen documentation

This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.
How to Generate Doxygen Documentation

To install doxygen run the following command:
```
sudo apt-get install doxygen

Now from the cloned directory run:

doxygen doxygen
```
Generated doxygen files are in html format and you can find them in ./docs folder. With the following command
```
cd docs
cd html
google-chrome index.html
```
## Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/dpiet/cpp-boilerplate
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of cpp-boilerplate

```
cd ~/workspace
mkdir -p boilerplate-eclipse
cd boilerplate-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../cpp-boilerplate/
```

## Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> 
Select "boilerplate-eclipse" directory created previously as root directory -> Finish

# Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


## Build

To build the project, in Eclipse, unfold boilerplate-eclipse project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

## Run

1. In Eclipse, right click on the boilerplate-eclipse in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)


## Debug


1. Set breakpoint in source file (i.e. double click in the left margin on the line you want 
the program to break).

2. In Eclipse, right click on the boilerplate-eclipse in Project Explorer, select Debug As -> 
Local C/C++ Application, choose the binaries to run (e.g. shell-app).

3. If prompt to "Confirm Perspective Switch", select yes.

4. Program will break at the breakpoint you set.

5. Press Step Into (F5), Step Over (F6), Step Return (F7) to step/debug your program.

6. Right click on the variable in editor to add watch expression to watch the variable in 
debugger window.

7. Press Terminate icon to terminate debugging and press C/C++ icon to switch back to C/C++ 
perspetive view (or Windows->Perspective->Open Perspective->C/C++).


## Plugins

- CppChEclipse

    To install and run cppcheck in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> cppcheclipse.
    Set cppcheck binary path to "/usr/bin/cppcheck".

    2. To run CPPCheck on a project, right click on the project name in the Project Explorer 
    and choose cppcheck -> Run cppcheck.


- Google C++ Sytle

    To include and use Google C++ Style formatter in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> Code Style -> Formatter. 
    Import [eclipse-cpp-google-style][reference-id-for-eclipse-cpp-google-style] and apply.

    2. To use Google C++ style formatter, right click on the source code or folder in 
    Project Explorer and choose Source -> Format

[reference-id-for-eclipse-cpp-google-style]: https://raw.githubusercontent.com/google/styleguide/gh-pages/eclipse-cpp-google-style.xml

- Git

    It is possible to manage version control through Eclipse and the git plugin, but it typically requires creating another project. If you're interested in this, try it out yourself and contact me on Canvas.
