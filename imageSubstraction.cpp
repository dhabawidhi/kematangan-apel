#include "header.h"
void dhaba::imageSubtraction(Mat image, Mat image2)
{
    image=grayscale(image);
    image2=grayscale(image2);
    //image=imread(image,CV_LOAD_IMAGE_GRAYSCALE);
    for(int i=0;i<image.rows; i++)
    {
        for (int j=0;j<image.cols;j++)
        {
            image.at<uchar>(i,j)=image.at<uchar>(i,j)-image2.at<uchar>(i,j);
        }
    }
    imshow("Image Substraction",image);
}
