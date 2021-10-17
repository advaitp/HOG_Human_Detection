cmake_minimum_required(VERSION 2.8) 
find_package(OpenCV REQUIRED )

add_executable(
    shell-app
    main.cpp
    Camera.cpp
    Detection.cpp
    Box.cpp
    Human.cpp
)

target_include_directories(shell-app PUBLIC ${CMAKE_SOURCE_DIR}/include
                                            ${CMAKE_SOURCE_DIR}/include/Eigen)

target_link_libraries(shell-app ${OpenCV_LIBS}) 
