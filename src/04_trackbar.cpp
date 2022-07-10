#include <opencv2/opencv.hpp>

using namespace cv;

// 回调函数只能传入特定参数，所以跟滚动条相关参数必须是全局变量
std::string win_name = "win_name";      // 滚动条附着的窗口名
int slider_value = 70, max_value = 100; // 滚动条的默认数值和最大数值
Mat img_in1, img_in2, img_out;          // 用于输入输出的图片

void onTrackbar(int, void*)
{
    double alpha = double(slider_value) / max_value;
    addWeighted(img_in1, alpha, img_in2, 1-alpha, 0.0, img_out);// 按比例融合两张图片，图片尺寸必须一致
    imshow(win_name, img_out);
}

int main()
{
    img_in1 = imread("../1.png");
    img_in2 = imread("../2.png");
    namedWindow(win_name);
    createTrackbar("bar_name", win_name, &slider_value, max_value, onTrackbar);
    onTrackbar(slider_value, 0);
    waitKey(0);
    return 0;
}