/*
 * ex2_7,ex2_8,ex2_9  Canny Edge
 */
#include <opencv2/opencv.hpp>
int ex2_7() {
	cv:: Mat img_rgb, img_gry, img_cny, img_pyr, img_pyr2;
	cv:: namedWindow( "Example Gray", cv:: WINDOW_AUTOSIZE );
	cv:: namedWindow( "Example Canny", cv:: WINDOW_AUTOSIZE );
	img_rgb = cv:: imread("src/main/resources/lena.jpg");
	cv:: cvtColor( img_rgb, img_gry, cv:: COLOR_BGR2GRAY);
	cv:: pyrDown( img_gry, img_pyr );
	cv:: pyrDown( img_pyr, img_pyr2 );
	cv:: imshow( "Example Gray", img_gry );
	cv:: Canny( img_pyr2, img_cny, 10, 100, 3, true );
	cv:: imshow( "Example Canny", img_cny );
	cv:: waitKey( 0);

	int x = 16, y = 32;
	cv:: Vec3b intensity = img_rgb.at<cv::Vec3b>( y, x);
	// ( Note: We could write img_rgb.at < cv:: Vec3b >( y, x)[ 0] )
	uchar blue = intensity[0];
	uchar green = intensity[1];
	uchar red = intensity[2];
	std:: cout << "At (x, y) = (" << x << ", " << y << "): (blue, green, red) = (" << (unsigned int) blue << ", " << (unsigned int) green << ", " << (unsigned int) red << ")" << std:: endl;

	return 0;
 }
