#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
		Mat image(200, 300, CV_8U, Scalar(255));
		namedWindow("keybord event", WINDOW_AUTOSIZE);
		imshow("key event", image);

		while(1)
		{
				int key = waitKeyEx(100);
				if (key == 27) break;

				switch(key)
				{
						case 'a': cout << "a key " << endl; break;
						case 'b': cout << "b key" << endl; break;
						case 0x41: cout << "A key" << endl; break;
						case 66: cout << "B key" << endl; break;

						case 75: cout << " left key" << endl; break;
						case 0x260000: cout << " up key" << endl; break;
						case 0x270000: cout << " right key" << endl; break;
						case 0x280000: cout << " down key" << endl; break;
				}
		}
		return 0;
}
