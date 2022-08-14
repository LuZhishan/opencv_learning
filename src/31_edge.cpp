#include <opencv2/opencv.hpp>

using namespace cv;

// 边缘检测是针对图像的一阶和二阶导数，对噪声敏感， 所以检测之前需要先滤波
// canny边缘检测：有两个检测阈值，可以检测到弱边缘
// sobel边缘检测：基于一阶导数，在xy两个方向上分别求导，不同方向的导数可以分离不同方向的边缘
// laplacian变换：基于二阶导数，

// canny可以自动转灰度图，但是检测效果很差，sobel需要手动转灰度
// laplacian变换需要手动滤波，然后再转灰度

int main()
{
    Mat img_1 = imread("../1.png", 0);
    Mat img_c, img_s, img_l;

    Canny(img_1, img_c, 50, 100, 3);//低阈值，高阈值，卷积核大小，高低阈值之间的比例推荐在2：1到3：1之间

    Mat grad_x, grad_y;
    Mat grad_x_abs, grad_y_abs;
    Sobel(img_1, grad_x, CV_16S, 1, 0, 3);  // 输出图像的深度，(1,0)代表在x方向商丘梯度，3和卷积核大小
    convertScaleAbs(grad_x, grad_x_abs);    // 导数有负值，所以需要转换一下
    Sobel(img_1, grad_y, CV_16S, 0, 1, 3);  // 这个就是在y方向上求梯度
    convertScaleAbs(grad_y, grad_y_abs);
    addWeighted(grad_x_abs, 0.5, grad_y_abs, 0.5, 0, img_s);

    GaussianBlur(img_1, img_1, Size(3, 3), 0, 0);
    Laplacian(img_1, img_l, CV_16S, 3);     // 输出图像深度，卷积核大小
    convertScaleAbs(img_l, img_l);

    imshow("0", img_l);
    waitKey(0);
    return 0;
}