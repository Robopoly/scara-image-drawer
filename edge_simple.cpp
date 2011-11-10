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
	if(blurFactor > 0)
		blur(gray, edge, Size(blurFactor,blurFactor));
		
	imshow("Bluring", edge);

	// Run the edge detector on grayscale
	Canny(edge, edge, edgeThresh, edgeThresh*3, 3);
	cedge = Scalar::all(0);
	
	findContours( edge, contours, CV_RETR_LIST, CV_CHAIN_APPROX_TC89_L1);
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
	CommandLineParser parser(argc, argv, keys);
	string filename = parser.get<string>("1");

	image = imread(filename, 1);
	if(image.empty()) {
		cout << "Cannot read image file: " << filename.c_str() << endl;
		return -1;
	}
    cedge.create(image.size(), image.type());
    cvtColor(image, gray, CV_BGR2GRAY);
	
	/*
	image_empty = imread("diff_empty.jpg", 1);
	image_empty_gray.create(image_empty.size(), image_empty.type());
	cvtColor(image_empty, image_empty_gray, CV_BGR2GRAY);
	
	image_full = imread("diff_full.jpg", 1);
	image_full_gray.create(image_full.size(), image_full.type());
	cvtColor(image_full, image_full_gray, CV_BGR2GRAY);
	
	image.create(image_empty_gray.size(), image_empty_gray.type());
	
	absdiff(image_full_gray, image_empty_gray, image);
	
	cedge.create(image.size(), image.type());
	* */
	//threshold(image, cedge, .3, 1, THRESH_BINARY);
	//cvtColor(image, gray, CV_BGR2GRAY);

	// Create a window
	namedWindow("Bluring", 1);
	namedWindow("Edge map", 1);
	
	//imshow("Edge map", cedge);
	//createTrackbar("threshold", "Edge map", &edgeThresh, 100, onTrackbar);
	
	// create a toolbar
	createTrackbar("Canny threshold", "Edge map", &edgeThresh, 100, onTrackbar);
	createTrackbar("Blur", "Bluring", &blurFactor, 15, onTrackbar);

	// Show the image
	onTrackbar(0, 0);

	// Wait for a key stroke; the same function arranges events processing
	waitKey(0);
	
	//imwrite("edge.png", cedge);
	
	//FILE *output_file = fopen ("output.drawing", "wt");
	ofstream output_file;
	output_file.open("output.v2");
	
	output_file << ".PROGRAM drawimage()" << endl;
	output_file << "       SET origin = TRANS(280,-80,198,0,180,0) ; Set the coordinates of the center of the circle" << endl;
	output_file << "       punch = 11.5" << endl;
	output_file << "       SPEED 250 MMPS ALWAYS" << endl;
	output_file << "       ACCEL 170, 170" << endl;
	output_file << "       COARSE 150 ALWAYS" << endl;
	output_file << "       MOVES origin ; Move linearly to the center of the workspace" << endl;
	output_file << "       BREAK ; Wait until destination has been reached" << endl << endl;
	
	vector<Point> segment;
	std::vector<vector<Point> >::size_type i;
	std::vector<Point>::size_type j;
	std::vector<Point>::size_type size, last;
	
	for(i = 0; i != contours.size(); i++) {
		segment = contours[i];
		size = segment.size();
		
		cout << "Segment :" << endl;
		output_file << "CALL moveto(" << x_to_robot(segment[0].y) << "," << y_to_robot(segment[0].x) << ", 0)" << endl;
		
		last = size-1;//min(size-1, size/2+4);
		for(j = 0; j <= last; j+=2) {
			cout << "\tx:" << segment[j].x << " y:" << segment[j].y << endl;
			output_file << "CALL moveto(" << x_to_robot(segment[j].y) << "," << y_to_robot(segment[j].x) << ", punch)" << endl;
		}
		
		output_file << "CALL moveto(" << x_to_robot(segment[last].y) << "," << y_to_robot(segment[last].x) << ", punch)" << endl;
		output_file << "CALL moveto(" << x_to_robot(segment[last].y) << "," << y_to_robot(segment[last].x) << ", 0)" << endl << endl;
	}
	
	output_file << "MOVES origin" << endl;
	output_file << "BREAK" << endl << endl;
	
	output_file << ".END";
	
	output_file.close();
	return 0;
}
