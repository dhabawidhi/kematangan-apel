#include "header.h"
Mat dhaba::cutImage(Mat threshold, Mat image)
{
    //Mat temp=Mat(image.rows,image.cols,image.type()/3,0.0);
    Mat temp(image.rows,image.cols,image.type(),Scalar(0,0,0));
    Mat_<Vec3b> _image=image;
    for(int y=0;y<threshold.rows;y++)
    {
        for(int x=0;x<threshold.cols;x++)
        {
            if(threshold.at<uchar>(y,x)!=0)
            {
                temp.at<Vec3b>(y,x)[0]=image.at<Vec3b>(y,x)[0];
                temp.at<Vec3b>(y,x)[1]=image.at<Vec3b>(y,x)[1];
                temp.at<Vec3b>(y,x)[2]=image.at<Vec3b>(y,x)[2];
            }
        }
    }
    //temp=threshold;
    //imshow("hasil cut", temp);
    return temp;
}
