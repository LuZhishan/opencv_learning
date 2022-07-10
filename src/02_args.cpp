# include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv) 
{
    if (argc != 3) 
    {
        cout << "usage: feature_extraction img1 img2" << endl;
        return -1;
    }
    Mat img_1 = imread(argv[1], 0);
    Mat img_2 = imread(argv[2], 1);
}