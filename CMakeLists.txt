cmake_minimum_required(VERSION 2.8)
project(opencv_01)

find_package(OpenCV 4 REQUIRED)


include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(01_io src/01_io.cpp)
target_link_libraries(01_io ${OpenCV_LIBS})