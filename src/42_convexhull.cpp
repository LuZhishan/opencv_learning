#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat img_1 = Mat::zeros(480, 640, CV_8UC3);  // 这里的尺寸是矩阵形式，
    RNG& rng = theRNG();

    while(1)
    {
        char k;
        int count = (unsigned)rng%100 +3;
        vector<Point> points;
        for (size_t i = 0; i < count; i++)
        {
            Point p(rng.uniform(160, 450), rng.uniform(120, 360));
            points.push_back(p);
            circle(img_1, p, 1, Scalar(0,0,255));
        }

        vector<int> hull;
        convexHull(Mat(points), hull, 1);
        Point point_0 = points[hull[hull.size() - 1]];
        for (size_t i = 0; i < hull.size(); i++)
        {
            Point p = points[hull[i]];
            line(img_1, point_0, p, Scalar(255,255,255));
            point_0 = p;
        }
        imshow("0", img_1);
        k = waitKey();
        if(k == 27)
            break;
        points.clear();
    }
    return 0;
}