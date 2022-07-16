#include <opencv2/opencv.hpp>

using namespace cv;

bool colorReduce(Mat &img_in, Mat &img_out, int div)
{
    img_out = img_in.clone();   // 克隆读进来的图片，防止后续对图片进行无意的修改, const Mat &img_in是没有用的
    for (size_t i = 0; i < img_in.rows; i++)
    {   
        uchar* data = img_in.ptr<uchar>(i);
        for (size_t j = 0; j < img_in.cols*img_in.channels(); j++)
        {
            data[j] = data[j] / div *div;
        }
    }
    return 1;
}

bool lookUpTable(Mat &img_in, Mat &img_out, int div)
{
    uchar table[256];           // 查表法速度更快
    for (size_t i = 0; i < 256; i++)
    {
        table[i] = table[i] / div *div;
    }

    img_out = img_in.clone();
    for (size_t i = 0; i < img_in.rows; i++)
    {   
        uchar* data = img_in.ptr<uchar>(i);
        for (size_t j = 0; j < img_in.cols*img_in.channels(); j++)
        {
            data[j] = table[data[j]];
        }
    }
    return 1;
}

int main()
{
    Mat img_1 = imread("../1.png");
    Mat img_2, img_3;
    img_2.create(img_1.rows, img_1.cols, img_1.type());
    img_3.copySize(img_1);

    double time_0 = static_cast<double>(getTickCount());
    colorReduce(img_1, img_2, 10);
    double time_1 = static_cast<double>(getTickCount());
    std::cout << (time_1 - time_0) / getTickFrequency() << std::endl;

    lookUpTable(img_1, img_3, 10);
    double time_2 = static_cast<double>(getTickCount());
    std::cout << (time_2 - time_1) / getTickFrequency() << std::endl;

    imshow("2", img_2);
    double time_3 = static_cast<double>(getTickCount());
    std::cout << (time_3 - time_2) / getTickFrequency() << std::endl;

    waitKey(0);
    return 0;
}