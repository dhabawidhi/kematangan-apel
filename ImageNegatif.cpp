#include "header.h"
void dhaba::imageNegatif(Mat image)
{
    Mat image2=grayscale(image);
    //image=imread(image,CV_LOAD_IMAGE_GRAYSCALE);
    for(int i=0;i<image2.rows; i++)
    {
        for (int j=0;j<image2.cols;j++)
        {
            image2.at<uchar>(i,j)=255-image2.at<uchar>(i,j);
        }
    }
    imshow("Image Negatif",image2);
}
