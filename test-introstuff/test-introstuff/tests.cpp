#include <iostream>
#include "opencv2\core\core.hpp"
#include "opencv2/flann/miniflann.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/photo/photo.hpp"
#include "opencv2/video/video.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/ml/ml.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/core/core_c.h"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/imgproc/imgproc_c.h"

using namespace std;
using namespace cv;

int main()
{
	//Code for creating an empty image window
	/*Mat img(1000, 1000, CV_8UC3, Scalar(100, 25, 50));

	if (img.empty())
	{
		cout << "Error : Image could not be loaded!" << endl;
		return -1;
	}

	namedWindow("Image Read", CV_WINDOW_NORMAL);

	imshow("Image Read", img);

	waitKey(0);

	destroyWindow("Image Read");*/

	//Code for video capture
	VideoCapture vidCap(0);

	if (!vidCap.isOpened())
	{
		cout << "Cannot open camera feed." << endl;
		system("pause"); //wait for a key press
		return -1;
	}

	//vidCap.set(CV_CAP_PROP_POS_MSEC, 100); //Starts 100 ms in

	//double vidFPS = vidCap.get(CV_CAP_PROP_FPS);

	//cout << "Frames Per Second: (" << vidFPS << " fps)" << endl;

	double vidWidth = vidCap.get(CV_CAP_PROP_FRAME_WIDTH);
	double vidHeight = vidCap.get(CV_CAP_PROP_FRAME_HEIGHT);

	cout << "Frame Size: " << vidWidth << " x " << vidHeight << endl;

	namedWindow("Video Playback", CV_WINDOW_NORMAL);

	while (1)
	{
		Mat vidFrame;

		bool frameSuccess = vidCap.read(vidFrame);

		if (!frameSuccess)
		{
			cout << "Could not load frame." << endl;
			break;
		}

		imshow("Video Playback", vidFrame);

		if (waitKey(30) == 27)
		{
			cout << "User pressed esc, exiting..." << endl;
			break;
		}
	}

	return 0;
}