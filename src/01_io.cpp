#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main()
{
    Mat img_in = imread("../1.png", 0); // 0就是灰度图，1就是彩色图，-1是带a通道，默认是1
                                        // 如果是1，读进来的图片是BGR通道
    if(!img_in.data)
    {
        std::cout << "No such img" << std::endl;
        return -1;
    }
    imshow("Title of window", img_in);
    waitKey(0);
    // imwrite("01.png", img_in);

    VideoCapture cap("../threebody.flv");   // 读取视频
    // VideoCapture cap(0);                 // 读取摄像头
    Size S = Size((int)cap.get(CAP_PROP_FRAME_WIDTH), (int)cap.get(CAP_PROP_FRAME_HEIGHT));
	int fps = cap.get(CAP_PROP_FPS);
    VideoWriter writer("../123.mp4", CAP_OPENCV_MJPEG, fps, S);// 文件名，编码格式，帧率，图像尺寸
    // while (1)
    for(int i = 0; i < 100; i++)
    {
        Mat frame;
        cap >> frame;
        if(frame.empty())
        {
            break;
        }
        // imshow("Title of window", frame);
        // waitKey(30);
        writer.write(frame);
    }
    return 0;
}