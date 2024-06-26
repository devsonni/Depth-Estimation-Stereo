cmake_minimum_required(VERSION 3.10)
project(DepthEstimation)

find_package(OpenCV REQUIRED)
include_directories(include/)
include_directories(include/opencv2)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(DepthEstimation src/Main.cpp)
target_link_libraries(DepthEstimation ${OpenCV_LIBS})
