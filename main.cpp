#include <iostream>
#include <opencv2/opencv.hpp>
#include <omp.h>
#include "dewarping.hpp"

#define ITER	819200

using namespace cv;
using namespace std;

int src_x[819200], src_y[819200], dst_x[819200], dst_y[819200];

int main() {
    VideoCapture capTheta;
    capTheta = VideoCapture(1);

    init_dewarping();

    Mat input, output;

    while(1) {
        capTheta >> input;
        output = image_dewarping(input.rows, input.cols, input);
        imshow("before", input);
        imshow("result", output);
        waitKey(10);
    }

    return 0;
}
