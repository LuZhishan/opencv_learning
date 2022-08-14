#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// 在二值图中查找和绘制轮廓

int main()
{
    Mat img_1 = imread("../1.png", 0);
    Mat img_2;
    Mat img_3 = Mat::zeros(img_1.rows, img_1.cols, CV_8UC3);
    img_2 = img_1 > 100;    // 截取img_1中像素大于100的，相当于一个简单的二值化

    vector<vector<Point>> contours; // 定义轮廓
    vector<Vec4i> hierarchy;        // 定义层次结构，表达轮廓之间的关系，分别是后一个、前一个、父轮廓、子轮廓
    findContours(img_2, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);// 第四个参数是检索模式，RETR_EXTERNAL只检测最外侧轮廓

    for(int i = 0; i >= 0; i = hierarchy[i][0])
    {
        drawContours(img_3, contours, i, Scalar(rand()&255, rand()&255, rand()&255), FILLED, 8, hierarchy);
    }

    imshow("0", img_3);
    waitKey(0);
    return 0;
}