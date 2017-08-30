#include "header.h"

void dhaba::yCbCr(Mat image)
{
    Mat bgr[3];   //destination array

    split(image,bgr);//split source
    /*Mat gy=bgr[0]; // for grayscale
    for(int i=0;i<image.rows; i++)
    {
        for (int j=0;j<image.cols;j++)
        {
            gy.at<uchar>(i,j)=char(round((bgr[0].at<uchar>(i,j)+bgr[1].at<uchar>(i,j)+bgr[2].at<uchar>(i,j))/3));
        }
    }
    Mat ycbcr;
    */
    Mat ycbcr[3];
    split(image,ycbcr);
    for(int i=0;i<image.rows;i++)
    {
        for(int j=0;j<image.cols;j++)
        {
            ycbcr[0].at<uchar>(i,j)=0+(round(0.229*bgr[0].at<uchar>(i,j))+round(0.587*bgr[1].at<uchar>(i,j))+round(0.114*bgr[2].at<uchar>(i,j)));
            ycbcr[1].at<uchar>(i,j)=128+(round(-0.169*bgr[0].at<uchar>(i,j))+round(-0.331*bgr[1].at<uchar>(i,j))+round(0.5*bgr[2].at<uchar>(i,j)));
            ycbcr[2].at<uchar>(i,j)=128+(round(0.5*bgr[0].at<uchar>(i,j))+round(-0.419*bgr[1].at<uchar>(i,j))+round(-0.081*bgr[2].at<uchar>(i,j)));
            //cout << ycbcr[0].at<uchar>(i,j) << endl;
        }
    }
    merge(ycbcr,3,image);
    //imshow("grayscale",gy);
    imshow("YCbCr",image);
}
