cmake_minimum_required(VERSION 2.8) 
find_package(OpenCV REQUIRED )

add_executable(
    shell-app
    Camera.cpp
    main.cpp
    Detection.cpp
    Human.cpp
    Box.cpp
)

target_include_directories(shell-app PUBLIC ${CMAKE_SOURCE_DIR}/include
                                            ${CMAKE_SOURCE_DIR}/include/Eigen
                                            ${OpenCV_INCLUDE_DIRS})

target_link_libraries(shell-app ${OpenCV_LIBS}) 
