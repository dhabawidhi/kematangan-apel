#include "header.h"

void dhaba::imageThresholding(Mat image)
{
    Mat image2=grayscale(image);
    for(int i=0;i<image2.rows; i++)
    {
        for (int j=0;j<image2.cols;j++)
        {
            //cout << i << " " << j << " " << bgr[0].at<uchar>(i,j) << endl;
            //image2.at<uchar>(i,j)=255-image2.at<uchar>(i,j);
            if (image2.at<uchar>(i,j)<151) image2.at<uchar>(i,j)=0;
            else image2.at<uchar>(i,j)=255;
        }
    }
    imshow("Image Thresholding Grayscale",image2);
}
