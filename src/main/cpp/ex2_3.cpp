#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/videoio/videoio.hpp"

using namespace cv;

int ex2_3(){
	namedWindow("play video", WINDOW_AUTOSIZE);
	VideoCapture cap;
	//cap.open(string(argv[1]));
	cap.open("src/main/resources/ben.mov");

	Mat frame;
	for(;;){
		cap >> frame;
		if(frame.empty()) break;
		imshow("Play Video", frame);
		if((char) waitKey(33) >=0) break;
	}
	return 0;
}
