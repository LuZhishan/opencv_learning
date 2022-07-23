#include <opencv2/opencv.hpp>

using namespace cv;

// 开运算：先腐蚀后膨胀，可以消除小物体，在纤细点分割物体
// 闭运算：先膨胀后腐蚀，可以消除小黑点
// 形态学梯度：膨胀-腐蚀，用来保留物体边缘
// 顶帽：原图-开运算，用来分离局部高亮点
// 黑帽：原图-闭运算，用来分离局部低光点


int main()
{
    Mat img_1 = imread("../1.png");

    Mat pengzhang, fushi;
    Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));      // 构建一个正方形，15x15的核
    Mat element2 = getStructuringElement(MORPH_CROSS, Size(15, 15));    // 交叉形核
    Mat element3 = getStructuringElement(MORPH_ELLIPSE, Size(15, 15));  // 椭圆形核

    dilate(img_1, pengzhang, element);  // 膨胀
    erode(img_1, fushi, element);       // 腐蚀

    Mat out;// 开运算、闭运算、形态学梯度、顶帽、黑帽
    morphologyEx(img_1, out, MORPH_OPEN, element);
    morphologyEx(img_1, out, MORPH_CLOSE, element);
    morphologyEx(img_1, out, MORPH_GRADIENT, element);
    morphologyEx(img_1, out, MORPH_TOPHAT, element);
    morphologyEx(img_1, out, MORPH_BLACKHAT, element);
    morphologyEx(img_1, out, MORPH_ERODE, element); // 腐蚀
    morphologyEx(img_1, out, MORPH_DILATE, element);// 膨胀

    imshow("0", img_1);
    waitKey(0);
    return 0;
}