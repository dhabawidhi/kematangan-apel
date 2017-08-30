#include "header.h"
void dhaba::contractStretching(Mat image)
{
    Mat bgr[3];   //destination array

    split(image,bgr);//split source
    Mat gy=bgr[0]; // for grayscale
    int valueMax=0, valueMin=255;
    for(int i=0;i<image.rows; i++)
    {
        for (int j=0;j<image.cols;j++)
        {
            gy.at<uchar>(i,j)=char(round((bgr[0].at<uchar>(i,j)+bgr[1].at<uchar>(i,j)+bgr[2].at<uchar>(i,j))/3));
            if(gy.at<uchar>(i,j) >= valueMax) valueMax=gy.at<uchar>(i,j);
            if(gy.at<uchar>(i,j) <= valueMin) valueMin=gy.at<uchar>(i,j);
        }
    }
    //F out =(f in -a)*b
    //a = min(f in ); b = 255/(max(f in )-min(f in ))
    for(int i=0;i<gy.rows; i++)
    {
        for (int j=0;j<gy.cols;j++)
        {
            gy.at<uchar>(i,j)=(gy.at<uchar>(i,j)-valueMin)*(255/(valueMax-valueMin));
        }
    }
    imshow("Contract Stretching", gy);
}
