#ifndef DEWARPING_H_
#define DEWARPING_H_

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <omp.h>

using namespace cv;
using namespace std;

int src_x[819200], src_y[819200], dst_x[819200], dst_y[819200];

bool init_dewarping(void);
Mat image_dewarping(int cols, int rows, Mat inMat);

#endif