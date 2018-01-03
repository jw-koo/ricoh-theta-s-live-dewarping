#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "dewarping.hpp"

#define ITER		819200

bool init_dewarping(void) {
	FILE *fp = NULL;
    fp = fopen("mapping.dat", "r");

	if(fp == NULL) {
		std::cout << "No mapping data" << std::endl;
		return false;
	}

    for(int i=0; i<ITER; i++)
    	fscanf(fp, "%d %d %d %d\n", &src_x[i], &src_y[i], &dst_x[i], &dst_y[i]);
	fclose(fp);

	return true;
}

Mat image_dewarping(int cols, int rows, Mat inMat) {
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
