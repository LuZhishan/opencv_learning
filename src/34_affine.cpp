#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// 仿射变换就是二维的旋转平移，再加上缩放

int main()
{
    Mat img_1 = imread("../1.png");


    imshow("0", img_1);
    waitKey(0);
    return 0;
}