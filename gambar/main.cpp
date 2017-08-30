#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <math.h>
#include <opencv/cxcore.h>

using namespace std;
using namespace cv;

void detection(Mat edge, Mat ori)
{
    for(int y = 0; y < ori.rows; y++)
    {
        uchar* edgePtr = edge.ptr<uchar>(y);
        Vec3b* imgPtr = ori.ptr<Vec3b>(y);
        for(int x = 0; x < ori.cols; x++)
        {
            if(edgePtr[x] != 0)
            {
                imgPtr[x][0] = 0;
                 imgPtr[x][1] = 255;
                  imgPtr[x][2] = 0;
            }
        }
    }
    imshow("Hasil deteksi", ori);
}

void orange_detection()
{
    IplImage* img = cvLoadImage("sumber/oranges.jpeg");
    IplImage* originals = cvLoadImage("sumber/oranges.jpeg");

    IplImage* R = cvCreateImage(cvGetSize(img), 8, 1);
    IplImage* G = cvCreateImage(cvGetSize(img), 8, 1);
    IplImage* B = cvCreateImage(cvGetSize(img), 8, 1);
    ///////////////////////////////////////////////////////
    IplImage* output1 = cvCreateImage(cvGetSize(img), 8, 1);
    IplImage* sub1 = cvCreateImage(cvGetSize(img), 8, 1);

    cvSplit(img,B,G,R,NULL);
    cvSub(R,G,sub1);

    cvThreshold(sub1, output1, 45, 255, CV_THRESH_BINARY);//melakukan proses threshold
    cvCanny(output1, output1,0,255,3);//untuk mendeteksi garis
    cvDilate(output1, output1, 0, 1);//untuk menebalkan garis

    Mat edge(output1);
    Mat mat_ori(img);
    detection(edge, mat_ori);
   // cvNamedWindow("originals");
    cvShowImage("originals", originals);
  //  cvShowImage("Hasil segmentasi jeruk dengan background", output1);
    cvWaitKey(0);
}


int main()
{
    orange_detection();
    return 0;
}
