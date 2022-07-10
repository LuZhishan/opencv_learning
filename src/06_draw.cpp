#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    // 生成一个480行640列的图片，也就是常见的640x480，这里是安装矩阵是形式
    // CV_8UC3是8位unsigned char类型3通道图片
    // Scalar指定颜色为黑色
    Mat img(480, 640, CV_8UC3, Scalar(0, 0, 0));
    // 后面的坐标是图片坐标系下的坐标，不是第几行第几列
    line(img, Point(10, 20), Point(10, 220), Scalar(0, 0, 255));
    rectangle(img, Rect(240, 320, 100, 50), Scalar(0, 255, 0), -1); // thickness 是线的粗细，-1代表实心绘制
    circle(img, Point(240, 320), 100, Scalar(255, 0, 0));
    // fillPoly(img, )

    imshow("123", img);
    waitKey(0);
}