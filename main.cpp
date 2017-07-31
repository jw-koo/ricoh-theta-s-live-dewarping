#include <iostream>
#include <opencv2/opencv.hpp>
#include <omp.h>

#define ITER	819200

using namespace cv;
using namespace std;

int src_x[819200], src_y[819200], dst_x[819200], dst_y[819200];

Mat imageStitch(int cols, int rows, Mat inMat) {
    Mat outMat = Mat(cols, rows, CV_8UC3, inMat.type());

	#pragma omp parallel
	#pragma omp for
	for(int i=0; i<ITER; i++) {
		outMat.at<Vec3b>(dst_x[i],dst_y[i])[0] = inMat.at<Vec3b>(src_x[i],src_y[i])[0];
		outMat.at<Vec3b>(dst_x[i],dst_y[i])[1] = inMat.at<Vec3b>(src_x[i],src_y[i])[1];
		outMat.at<Vec3b>(dst_x[i],dst_y[i])[2] = inMat.at<Vec3b>(src_x[i],src_y[i])[2];
	}	
    return outMat;
}

int main() {
	VideoCapture capTheta;
	capTheta = VideoCapture(1);
	
    Mat input;
    FILE *fp = NULL;    
    fp = fopen("mapping.dat", "r");
    for(int i=0; i<ITER; i++)
    	fscanf(fp, "%d %d %d %d\n", &src_x[i], &src_y[i], &dst_x[i], &dst_y[i]);
	fclose(fp);
	
	Mat output;
	
	while(1) {
   		capTheta >> input;
   		output = imageStitch(input.rows, input.cols, input);
		imshow("before", input);
		imshow("result", output);
		waitKey(10);
   	}
   	
    return 0;
}
