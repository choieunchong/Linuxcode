#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
		VideoCapture capture;
		capture.open("./image/video_file.avi");
		CV_Assert(capture.isOpened());

		double fps = 29.97;
		int delay = cvRound(1000.0 / fps);
		Size size(640, 360);
		int fourcc = VideoWriter::fourcc('D', 'X', '5', '0');

		cout << "wit x height : " << size << endl;
		cout << "Videw::fourcc:" << fourcc << endl;
		cout << "delay: " << delay << endl;
		cout << "fps: " << fps << endl;

		VideoWriter writer;
		writer.open("../image/video_file.avi", fourcc, fps, size);
		CV_Assert(writer.isOpened());

		for(;;){
				Mat frame;
				capture >> frame;
				writer << frame;

				imshow("cam view" , frame);
				if(waitKey(delay) >= 0)
						break;
		}
		return 0;
}
