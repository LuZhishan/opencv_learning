#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    Mat img_1 = imread("../4.png", 0);
    if(!img_1.data)
    {
        return -1;
    }
    Mat img_out1, img_out2;
    threshold(img_1, img_out1, 150, 255, THRESH_BINARY_INV);
    imshow("1", img_out1);

    int blockSize = 25; // 必须是奇数的完全平方数
    int constValue = 10;// 从平均值或加权平均值中减去常数
    adaptiveThreshold(img_1, img_out2, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY_INV, blockSize, constValue);
    imshow("2", img_out2);

    waitKey(0);
    return 0;
}