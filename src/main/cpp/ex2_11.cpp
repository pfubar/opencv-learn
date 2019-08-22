/*
 * ex2_11  transform and write video
 */

#include <opencv2/opencv.hpp>
#include <iostream>

int ex2_11() {
	cv:: namedWindow( "Example 2-11", cv:: WINDOW_AUTOSIZE );
	cv:: namedWindow( "Log_Polar", cv:: WINDOW_AUTOSIZE );
	// ( Note: could capture from a camera by giving a camera id as an int.)
	cv:: VideoCapture capture("src/main/resources/ben.mov");
	double fps = capture.get(CV_CAP_PROP_FPS);
	cv:: Size size(
		(int) capture.get( CV_CAP_PROP_FRAME_WIDTH ),
		(int) capture.get( CV_CAP_PROP_FRAME_HEIGHT )
	);
	cv:: VideoWriter writer;
	writer.open( "out/out.avi", CV_FOURCC('M','J','P','G'), fps, size );
	cv:: Mat logpolar_frame, bgr_frame;
	for(;;) {
		capture >> bgr_frame;
		if( bgr_frame.empty() ) break;	 // end if done
		cv::imshow( "Example 2-11", bgr_frame );
		cv::logPolar(
			bgr_frame, // Input color frame
			logpolar_frame, // Output log-polar frame
			cv::Point2f( // Centerpoint for log-polar transformation
				bgr_frame.cols / 2, // x
				bgr_frame.rows / 2 // y
			),
			40, // Magnitude (scale parameter)
			CV_WARP_FILL_OUTLIERS // Fill outliers with 'zero'
		);
		cv:: imshow( "Log_Polar", logpolar_frame );
		writer << logpolar_frame;
		char c = (char) cv:: waitKey(33);
		if( c == 27 ) break; // allow the user to break out
	}
	capture.release();
	return 0;
}



