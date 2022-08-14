#include <opencv2/opencv.hpp>
#include <opencv2/aruco/charuco.hpp>

using namespace cv;
using namespace std;

int main()
{
    // Mat img_1 = imread("/home/fanliang/workspace/img/20220727static/0/1658914134.701965.png");
    Mat img_1 = imread("../123.png");

    Ptr<aruco::Dictionary> dictionary = aruco::getPredefinedDictionary(aruco::DICT_4X4_50);
    Ptr<aruco::CharucoBoard> charucoboard = aruco::CharucoBoard::create(8, 5, 0.15, 0.117, dictionary);
    Ptr<aruco::Board> board = charucoboard.staticCast<aruco::Board>();

    vector<int> markerIds, charucoIds;
    vector<vector<Point2f>> markerCorners, rejectedMarkers;
    vector<Point2f> charucoCorners;
    aruco::detectMarkers(img_1, dictionary, markerCorners, markerIds);
    int interpolatedCorners = 0;
    Mat img_2 = img_1.clone();
    if(markerIds.size() > 0)
    {
        interpolatedCorners = aruco::interpolateCornersCharuco(
                markerCorners, markerIds, img_1, charucoboard, charucoCorners, charucoIds);
        if(charucoIds.size() > 0)
        {
            // aruco::drawDetectedCornersCharuco(img_2, charucoCorners, charucoIds, Scalar(0,0,255));
            for(auto id : charucoIds)
                circle(img_2, charucoCorners[id], 5, Scalar(0,0,255), 0);
        }
    }
    // imshow("2", img_2);
    imwrite("../test.png", img_2);









    // imshow("0", img_1);
    // waitKey(0);
    return 0;
}