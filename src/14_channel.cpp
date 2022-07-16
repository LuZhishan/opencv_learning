#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    Mat img_1 = imread("../1.png");
    Mat img(480, 640, CV_8UC1, Scalar(0));
    std::vector<Mat> channels;
    split(img_1, channels);

    channels.at(0) = img;
    // img.copyTo(channels.at(0));
    Mat out_img;
    merge(channels, out_img);

    imshow("1", out_img);
    waitKey(0);
    return 0;
}