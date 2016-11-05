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
	Mat img(1000, 1000, CV_8UC3, Scalar(100, 25, 50));

	if (img.empty())
	{
		cout << "Error : Image could not be loaded!" << endl;
		return -1;
	}

	namedWindow("Image Read", CV_WINDOW_NORMAL);

	imshow("Image Read", img);

	waitKey(0);

	destroyWindow("Image Read");

	return 0;
}