cmake_minimum_required(VERSION 2.8)
project(opencv_01)

find_package(OpenCV 4 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

# add_executable(01_io src/01_io.cpp)
# target_link_libraries(01_io ${OpenCV_LIBS})
# add_executable(03_mouse src/03_mouse.cpp)
# target_link_libraries(03_mouse ${OpenCV_LIBS})
# add_executable(04_trackbar src/04_trackbar.cpp)
# target_link_libraries(04_trackbar ${OpenCV_LIBS})
add_executable(06_draw src/06_draw.cpp)
target_link_libraries(06_draw ${OpenCV_LIBS})