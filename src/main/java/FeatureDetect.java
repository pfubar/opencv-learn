import org.opencv.core.Core;
import org.opencv.core.Mat;
import org.opencv.core.MatOfKeyPoint;
import org.opencv.features2d.FeatureDetector;
import org.opencv.features2d.Features2d;
//import org.opencv.highgui.Highgui;
import org.opencv.imgcodecs.Imgcodecs;

public class FeatureDetect {
	
	  static{ System.loadLibrary(Core.NATIVE_LIBRARY_NAME); }

	public static void main (String[]args){
		System.out.println("\nRunning DetectFaceDemo");

		Mat image = Imgcodecs.imread(Thread.currentThread().getContextClassLoader().getResource("bicycle_w/images.jpeg").getPath());
		Mat outImage = new Mat();
		FeatureDetector fd = FeatureDetector.create(FeatureDetector.AKAZE);
		MatOfKeyPoint keypoints = new MatOfKeyPoint();
		fd.detect(image, keypoints);
		
		Features2d.drawKeypoints(image, keypoints, outImage);
		
		// Save the visualized detection.
		String filename = "target/featureDetection.png";
		System.out.println(String.format("Writing %s", filename));
		Imgcodecs.imwrite(filename, outImage);
	}
}
