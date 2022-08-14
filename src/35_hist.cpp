#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// 直方图均衡化的作用是让亮的更亮，暗的更暗，扩大原图的动态范围
// 直方图均衡化的输入必须是灰度图

int main()
{
    Mat img_1 = imread("../1.png", 0);
    equalizeHist(img_1, img_1);

    imshow("0", img_1);
    waitKey(0);
    return 0;
}