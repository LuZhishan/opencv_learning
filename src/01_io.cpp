#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main()
{
    Mat img_in = imread("../1.png", 0); // 0就是灰度图，1就是彩色图，默认是1
    imshow("Title of window", img_in);
    waitKey(0);
    return 0;
}