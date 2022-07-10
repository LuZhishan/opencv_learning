#include <opencv2/opencv.hpp>

using namespace cv;

void onMouse(int event, int x, int y, int flags, void* param)
{
	Mat *img = reinterpret_cast<Mat*>(param);
	switch (event)
	{
	case 1:
		std::cout << "单击鼠标左键" << std::endl;
		std::cout << "此点的坐标为：" << x << "," << y << std::endl;
		break;
	case 2:
		std::cout << "单击鼠标右键" << std::endl;
		std::cout << "此点的灰度之为：" << static_cast<int>(img->at<uchar>(cv::Point(x, y))) << std::endl;

	default:
		break;
	}
}


int main()
{
	Mat img_in = imread("../1.png");
	while(1)
	{
		cv::setMouseCallback("123", onMouse, &img_in);
		imshow("123", img_in);
		int key = waitKey(30);
		if(key == 27)	// 按esc键退出
		{
			break;
		}
	}
	return 0;
}