#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    Mat img_1 = imread("../1.png");


    imshow("0", img_1);
    waitKey(0);
    return 0;
}