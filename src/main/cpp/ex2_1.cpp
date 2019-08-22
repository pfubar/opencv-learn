/*
 * ex2-1 show image
 */
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int ex2_1(){
	Mat img = imread("src/main/resources/lena.jpg", -1);// read the file
	if(img.empty()) return -1;
	namedWindow( "Display window", CV_WINDOW_AUTOSIZE );// create a window for display.
	imshow( "Display window", img );// show our image inside it.
	waitKey(0);// wait for a keystroke in the window
	return 0;
}
