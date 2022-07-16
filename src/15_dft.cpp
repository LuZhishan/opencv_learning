#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    Mat img_1 = imread("../1.png");
    Mat img_f;
    img_1.convertTo(img_f, CV_32F);
    std::vector<Mat> channel;
    split(img_f, channel);
    Mat img_mag; magnitude(channel.at(0), channel.at(1), img_mag);
    Mat img_log; log(img_f, img_log);

    imshow("0", img_mag);
    waitKey(0);
    return 0;
}