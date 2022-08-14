#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat img_1 = imread("../1.png");
    Mat img_2; img_2.copySize(img_1);
    Mat map_x, map_y;
    map_x.create(img_1.size(), CV_32FC1); map_y.create(img_1.size(), CV_32FC1);
    for (size_t i = 0; i < img_1.rows; i++)
    {
        for (size_t j = 0; j < img_1.cols; j++)
        {
            map_x.at<float>(i, j) = static_cast<float>(j);  // 列保持不变
            map_y.at<float>(i, j) = static_cast<float>(img_1.rows - i); // 行进行对调
        }   // 最终结果就是上下翻转
        
    }
    remap(img_1, img_2, map_x, map_y, INTER_LINEAR);

    // 其他翻转函数
    flip(img_1, img_2, -1); // 1是左右翻转，0是上下翻转，-1同时上下左右翻转

    imshow("1", img_1);
    imshow("2", img_2);
    waitKey(0);
    return 0;
}