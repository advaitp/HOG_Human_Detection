set(GTEST_SHUFFLE 1)
cmake_minimum_required(VERSION 2.8) 
find_package(OpenCV REQUIRED)

add_executable(cpp-test main.cpp)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(cpp-test PUBLIC gtest ${OpenCV_LIBS})

