#include "header.h"

Mat dhaba::grayscale(Mat image)
{
    Mat bgr[3];   //destination array

    split(image,bgr);//split source
    Mat gy=bgr[0]; // for grayscale
    for(int i=0;i<image.rows; i++)
    {
        for (int j=0;j<image.cols;j++)
        {
            gy.at<uchar>(i,j)=char(round((bgr[0].at<uchar>(i,j)+bgr[1].at<uchar>(i,j)+bgr[2].at<uchar>(i,j))/3));
        }
    }
    //imshow("grayscale",gy);
    return gy;
}

