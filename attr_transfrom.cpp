#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

uchar bilinear_value(Mat img, int x, int ){

		if(x >= img.cols - 1) x--;
		if( y >= img.rows -1) y--;

		Point pt((int)x, (int)y);
		int A = img.at<uchar>(pt);
		int B = img.at<uchar>(pt + Point(0, 1));
		int C = img.at<uchar>(pt + Point(1, 0));
		int D = img.at<uchar>(pt + Point(1, 1));

		double alpha = y - pt.y;
		double beta = x - pt.x;

		int M1 = A + (int)cvRound(alpha * (B - A));
		int M2 = C + (int)cvRound(alpha * (D - C));
        int P = M1+ (int)cvRound(beta * (M2 - M1));
		return saturate_cast<uchar>(P);
}

