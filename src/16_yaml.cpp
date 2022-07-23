#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    FileStorage wfs("../test.yaml", FileStorage::WRITE);    // 初始化一个文件系统对象，该对象操作的文件名为test，操作方式为写入
    wfs << "number" << 5;           // 写入数字
    wfs << "string" << "my_name";   // 写入字符串
    wfs << "cv_Mat" << Mat_<uchar>::zeros(3,1);
    wfs.release();                  // 写完之后释放该文件

    FileStorage rfs("../test.yaml", FileStorage::READ);
    int number;
    rfs["number"] >> number;
    std::cout << number << std::endl;
    rfs.release();


    return 0;
}