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
# add_executable(06_draw src/06_draw.cpp)
# target_link_libraries(06_draw ${OpenCV_LIBS})
# add_executable(11_pixel src/11_pixel.cpp)
# target_link_libraries(11_pixel ${OpenCV_LIBS})
# add_executable(12_roi src/12_roi.cpp)
# target_link_libraries(12_roi ${OpenCV_LIBS})
# add_executable(13_threshold src/13_threshold.cpp)
# target_link_libraries(13_threshold ${OpenCV_LIBS})
# add_executable(14_channel src/14_channel.cpp)
# target_link_libraries(14_channel ${OpenCV_LIBS})
# add_executable(15_dft src/15_dft.cpp)
# target_link_libraries(15_dft ${OpenCV_LIBS})
# add_executable(16_yaml src/16_yaml.cpp)
# target_link_libraries(16_yaml ${OpenCV_LIBS})

# add_executable(31_edge src/31_edge.cpp)
# target_link_libraries(31_edge ${OpenCV_LIBS})
# add_executable(32_hough src/32_hough.cpp)
# target_link_libraries(32_hough ${OpenCV_LIBS})
# add_executable(33_remap src/33_remap.cpp)
# target_link_libraries(33_remap ${OpenCV_LIBS})
# add_executable(41_contours src/41_contours.cpp)
# target_link_libraries(41_contours ${OpenCV_LIBS})
add_executable(42_convexhull src/42_convexhull.cpp)
target_link_libraries(42_convexhull ${OpenCV_LIBS})







# add_executable(cal src/cal.cpp)
# target_link_libraries(cal ${OpenCV_LIBS})