#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    Mat img_1 = imread("../1.png");
    Mat img_2 = imread("../3.png");
    Mat img_3  = imread("../3.png", 0);  
    Mat mask;   
    threshold(img_3, mask, 50, 255, THRESH_BINARY_INV);   // 掩膜是灰度图，把非零像素保留下来，0像素透明化
    Mat roi = img_1(Rect(120, 20, 200, 200));
    imshow("roi1", roi);
    img_2.copyTo(roi, mask);

    imshow("123", img_1);
    imshow("roi2", roi);
    imshow("mask", mask);
    waitKey(0);
    return 0;
}