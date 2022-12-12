#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
		Mat m1(4, 3, CV_32FC3);
		cout << "Di  =" <<m1.dims << endl;
		cout << "row =" << m1.rows << endl;
		cout << "cols =" <<m1.cols << endl;
		cout << "rc =" << m1.size() << endl << endl;

		cout <<" total << " << m1.total() << endl;
		cout << "eSize =" <<m1.elemSize() << endl;
		cout << "ch =" << m1.elemSize1() << endl << endl;

		cout << "type = " << m1.type() << endl;
		cout << "type(c | de) = " << ((m1.channels() - 1) << 3) + m1.depth() << endl;
		cout << " dept = " << m1.depth() << endl;
		cout << "cha =" << m1.channels() << endl << endl;

		cout << "step = " << m1.step << endl;
		cout <<"step1() = " << m1.step1() << endl;
		return 0;
}

