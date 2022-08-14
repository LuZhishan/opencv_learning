#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// 霍夫直线的输入必须是二值图，或者canny边缘检测的结果（边缘检测的结果也是二值图）
// 霍夫圆的输入不需要二值图

int main()
{
    Mat img_1 = imread("../1.png", 0);
    Mat img_c, img_line;
    img_line = img_1.clone();
    Canny(img_1, img_c, 50 ,100, 3);
    vector<Vec2f> lines;
    // HoughLines(img_c, lines, 1, CV_PI/180, 150); // 距离精度(像素)，角度精度(弧度)，累加阈值
    // for(auto h_line : lines)
    // {
    //     float rho = h_line[0], theta = h_line[1];
    //     Point p1, p2;
    //     double a = cos(theta), b = sin(theta);
    //     double x0 = a * rho, y0 = b * rho;
    //     p1.x = cvRound(x0 + 1000*(-b));
    //     p1.y = cvRound(y0 + 1000*( a));
    //     p2.x = cvRound(x0 - 1000*(-b));
    //     p2.y = cvRound(y0 - 1000*( a));
    //     line(img_line, p1, p2, Scalar(255), 1);        
    // }

    vector<Vec4i> plines;
    HoughLinesP(img_c, plines, 1, CV_PI/180, 80, 50, 10);// 距离精度(像素)，角度精度(弧度)，累加阈值，直线长度，点与点之间最大距离
    for(auto h_line : plines)
    {
        line(img_line, Point(h_line[0], h_line[1]), Point(h_line[2], h_line[3]), Scalar(255), 1);
    }

    vector<Vec3f> circles;
    HoughCircles(img_1, circles, HOUGH_GRADIENT, 1.5, 10, 200, 100, 0, 0);
    // 检测方法是霍夫梯度，1.5是累加器，10是圆与圆之间的最小距离，200是canny边缘检测的高阈值，地狱之等于高阈值的一半，100是累加阈值
    // 最后两个参数分别是最小圆半径和最大圆半径


    imshow("0", img_line);
    waitKey(0);
    return 0;
}