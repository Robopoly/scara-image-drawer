#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace cv;
using namespace std;

int edgeThresh = 20;
int blurFactor = 6;
int edgeThresh2 = 120;
int cannyThresh = 40;
Scalar WHITE = Scalar(255,255,255);

Mat image_empty, image_full, image_full_gray;
Mat image, gray, edge, cedge, gray_edge;
vector<vector<Point> > contours;
vector<Vec4i> hierarchy;

// define a trackbar callback
void onTrackbar(int, void*)
{
	int blursize = blurFactor*3-blurFactor%2 + 1;
	
	threshold(gray, cedge, edgeThresh, 255, THRESH_BINARY);
	GaussianBlur(cedge, edge, Size(blursize, blursize), blurFactor);
	threshold(edge, cedge, edgeThresh2, 255, THRESH_BINARY);
	
	findContours( cedge, contours, hierarchy, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);
	
	std::vector<Vec4i>::size_type i;
	double area;
	
	for(i = 0; i != hierarchy.size(); i++) {
		area = fabs(contourArea(contours[i]));
		
		if(area > 500) {
			drawContours( cedge, contours, i, WHITE, CV_FILLED);
		}
	}
	
	GaussianBlur(image_full, edge, Size(blursize, blursize), blurFactor);
	image_full.copyTo(edge, cedge);
	cvtColor(edge, image_full_gray, CV_BGR2GRAY);
	//blur(image_full_gray, gray_edge, Size(3,3));
	
	edge = Scalar::all(0);
	Canny(image_full_gray, image_full_gray, cannyThresh, cannyThresh*3, 3);
	image_full.copyTo(edge, image_full_gray);
	
	imshow("Diff", edge);
}

const char* keys = 
{
	"{1| |images/diff_empty.jpg|input image name 1}"
	"{2| |images/diff_full.jpg|input image name 2}"
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
	CommandLineParser parser(argc, argv, keys);
	string filename1 = parser.get<string>("1");
	string filename2 = parser.get<string>("2");
	
	image_empty = imread(filename1, 1);
	image_full = imread(filename2, 1);
	
	if (image_empty.empty() || image_full.empty()) {
		cout << "Could not read image file " << filename1 << " or " << filename2 << "." << endl;
		return -1;
	}
	
	image.create(image_empty.size(), image_empty.type());
	
	absdiff(image_full, image_empty, image);
	cvtColor(image, gray, CV_BGR2GRAY);
	
	namedWindow("Diff", 1);	
	//imshow("Diff", image);
	
	//imwrite("diff.png", cedge);
	
	createTrackbar("Threshold 1", "Diff", &edgeThresh, 255, onTrackbar);
	createTrackbar("Blur", "Diff", &blurFactor, 60, onTrackbar);
	createTrackbar("Threshold 2", "Diff", &edgeThresh2, 255, onTrackbar);
	createTrackbar("Canny", "Diff", &cannyThresh, 255, onTrackbar);
	
	// create a toolbar
	//createTrackbar("Canny threshold", "Edge map", &edgeThresh, 100, onTrackbar);
	//createTrackbar("Blur", "Bluring", &blurFactor, 15, onTrackbar);

	// Show the image
	onTrackbar(0, 0);
	
	// Wait for a key stroke; the same function arranges events processing
	waitKey(0);
	
	imwrite("edge.png", edge);
	
	return 0;
}
