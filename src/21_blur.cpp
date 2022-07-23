#include <opencv2/opencv.hpp>

using namespace cv;

// 方框滤波和均值滤波基本一致
// 高斯滤波用于去除高斯噪声
// 中值滤波用于去除脉冲噪声和椒盐噪声，它
// 双边滤波会保留高频信息，所以可以保留物体的边缘，同时无法去除高频噪声


int main()
{
    Mat img_1 = imread("../1.png");

    Mat mean_blur, g_blur;   // 线性滤波器
    blur(img_1, mean_blur, Size(3, 3));
    GaussianBlur(img_1, g_blur, Size(3, 3), 0, 0);  // 最后两个参数是高斯分布在xy两个方向上的标准差

    Mat median_filter, bilatetal_filter;    // 非线性滤波器
    medianBlur(img_1, median_filter, 7);
    bilateralFilter(img_1, bilatetal_filter, 25, 25*2, 25.0/2);


    imshow("0", img_1);
    waitKey(0);
    return 0;
}