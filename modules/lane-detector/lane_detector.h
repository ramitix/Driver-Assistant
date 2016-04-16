#pragma once

#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

class LaneDetector
{
public:
	// Initialize with a sample image
	LaneDetector(Mat image);
	static bool IsOutOfLane(Mat image);
	static vector<Vec4i> GetLanes(Mat image);
	static void DrawLanes(Mat image, vector<Vec4i> lanes, Scalar color, int thickness);

private:
	// Returns a binary image in which 
	// 1 corresponds to white area, 0 corresponds to other colors
	static Mat GetWhiteMask(Mat image, bool maskFlag);
	static Mat mask_for_elim;
	const static double kLaneTresh;
};