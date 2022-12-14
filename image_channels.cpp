#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
		Mat image = imread("./lena.bmp",IMREAD_COLOR);
		CV_Assert(image.data);

		Mat bgr[3];
		split(image, bgr);

		imshow("image", image);
		imshow("blue ch", bgr[0]);
		imshow("green ch", bgr[1]);
		imshow("red ch", bgr[2]);
		waitKey(0);
		return 0;
}

