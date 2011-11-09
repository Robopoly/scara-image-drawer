#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace cv;
using namespace std;

int edgeThresh = 1;
int blurFactor = 3;
Mat image_empty, image_full;
Mat image_empty_gray, image_full_gray;
Mat image, gray, edge, cedge;
vector<vector<Point> > contours;

// define a trackbar callback
void onTrackbar(int, void*)
{
	//if(blurFactor > 0)
	//	blur(gray, edge, Size(blurFactor,blurFactor));
		
	//imshow("Bluring", edge);

	// Run the edge detector on grayscale
	//Canny(edge, edge, edgeThresh, edgeThresh*3, 3);
	cedge = Scalar::all(0);
	
	findContours( gray, contours, CV_RETR_LIST, CV_CHAIN_APPROX_TC89_KCOS);
	drawContours( cedge, contours, -1, Scalar(128,255,255), 1, CV_AA);
	
	//threshold(image, cedge, (double)edgeThresh, 256, THRESH_BINARY);
	
	//image.copyTo(cedge, edge);
	
	imshow("Edge map", cedge);
}

const char* keys = 
{
	"{1| |fruits.jpg|input image name}"
};

double x_to_robot(int x)
{
	return (-x/(double)2.);
}

double y_to_robot(int y)
{
	return (y/(double)2.);
}


int main( int argc, const char** argv )
{
	//CommandLineParser parser(argc, argv, keys);
	//string filename = parser.get<string>("1");
	
	image_empty = imread("diff_empty.jpg", 1);
	image_empty_gray.create(image_empty.size(), image_empty.type());
	cvtColor(image_empty, image_empty_gray, CV_BGR2GRAY);
	
	image_full = imread("diff_full.jpg", 1);
	image_full_gray.create(image_full.size(), image_full.type());
	cvtColor(image_full, image_full_gray, CV_BGR2GRAY);
	
	image.create(image_empty_gray.size(), image_empty_gray.type());
	
	absdiff(image_full_gray, image_empty_gray, image);
	
	//cedge.create(image.size(), image.type());
	
	threshold(image, cedge, 50, 255, THRESH_BINARY);
	//cvtColor(image, gray, CV_BGR2GRAY);

	// Create a window
	//namedWindow("Bluring", 1);
	//namedWindow("Diff", 1);	
	//imshow("Diff", image);
	
	imwrite("diff.png", cedge);
	
	//createTrackbar("threshold", "Edge map", &edgeThresh, 100, onTrackbar);
	
	// create a toolbar
	//createTrackbar("Canny threshold", "Edge map", &edgeThresh, 100, onTrackbar);
	//createTrackbar("Blur", "Bluring", &blurFactor, 15, onTrackbar);

	// Show the image
	//onTrackbar(0, 0);

	// Wait for a key stroke; the same function arranges events processing
	//waitKey(0);
	
	//imwrite("edge.png", cedge);


	return 0;
}
