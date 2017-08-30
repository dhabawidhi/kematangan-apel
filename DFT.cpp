#include "header.h"
void dhaba::DFT(Mat image)
{
    double pi=3.14159265359;
    Mat image2=grayscale(image);
    Mat transformDFT=image2;
    double sum=0.0;
    double b=0.0;
    int panjang=transformDFT.cols;
    int lebar=transformDFT.rows;
    for(int u=0;u<transformDFT.cols/2;u++)
    {
        for(int v=0;v<transformDFT.rows/2;v++)
        {
            for(int i=0;i<image2.cols;i++)
            {
                for(int j=0;j<image2.rows;j++)
                {
                    b=-2*pi*(u*1.0*i/image2.cols+v*1.0*j/image2.rows);
                    sum=sum+exp(b)*image2.at<uchar>(i,j);
                    //sum=sum+image2.at<uchar>(i,j)*1.0*exp(-2*pi*(u*1.0*i/image2.cols+v*1.0*j/image2.rows));
                    //sum=image2.at<uchar>(i,j)*1.0*exp(-2*pi*(u*1.0*i/image2.cols+v*1.0*j/image2.rows));
                    //sum=s
                }
            }
            //cout << u << " " << v << " " << int(sum) << endl;
            if (sum>=255) sum=255;
            transformDFT.at<uchar>(transformDFT.rows/2-v,transformDFT.cols/2+u)=sum;
            sum=0.0;
        }
    }
    for(int u=0;u<transformDFT.cols/2;u++)
    {
        for(int v=0;v<transformDFT.rows/2;v++)
        {
            for(int i=0;i<image2.cols;i++)
            {
                for(int j=0;j<image2.rows;j++)
                {
                    b=-2*pi*(u*1.0*i/image2.cols+(-v)*1.0*j/image2.rows);
                    sum=sum+exp(b)*image2.at<uchar>(i,j);
                    //sum=sum+image2.at<uchar>(i,j)*1.0*exp(-2*pi*(u*1.0*i/image2.cols+v*1.0*j/image2.rows));
                    //sum=image2.at<uchar>(i,j)*1.0*exp(-2*pi*(u*1.0*i/image2.cols+v*1.0*j/image2.rows));
                    //sum=s
                }
            }
            //cout << u << " " << v << " " << int(sum) << endl;
            if (sum>=255) sum=255;
            transformDFT.at<uchar>(transformDFT.rows/2+v,transformDFT.cols/2+u)=sum;
            sum=0.0;
        }
    }
    for(int u=0;u<transformDFT.cols/2;u++)
    {
        for(int v=0;v<transformDFT.rows/2;v++)
        {
            for(int i=0;i<image2.cols;i++)
            {
                for(int j=0;j<image2.rows;j++)
                {
                    b=-2*pi*((-u)*1.0*i/image2.cols+v*1.0*j/image2.rows);
                    sum=sum+exp(b)*image2.at<uchar>(i,j);
                    //sum=sum+image2.at<uchar>(i,j)*1.0*exp(-2*pi*(u*1.0*i/image2.cols+v*1.0*j/image2.rows));
                    //sum=image2.at<uchar>(i,j)*1.0*exp(-2*pi*(u*1.0*i/image2.cols+v*1.0*j/image2.rows));
                    //sum=s
                }
            }
            //cout << u << " " << v << " " << int(sum) << endl;
            if (sum>=255) sum=255;
            transformDFT.at<uchar>(transformDFT.rows/2+v,transformDFT.cols/2-u)=sum;
            sum=0.0;
        }
    }
    for(int u=0;u<transformDFT.cols/2;u++)
    {
        for(int v=0;v<transformDFT.rows/2;v++)
        {
            for(int i=0;i<image2.cols;i++)
            {
                for(int j=0;j<image2.rows;j++)
                {
                    b=-2*pi*((-u)*1.0*i/image2.cols+(-v)*1.0*j/image2.rows);
                    sum=sum+exp(b)*image2.at<uchar>(i,j);
                    //sum=sum+image2.at<uchar>(i,j)*1.0*exp(-2*pi*(u*1.0*i/image2.cols+v*1.0*j/image2.rows));
                    //sum=image2.at<uchar>(i,j)*1.0*exp(-2*pi*(u*1.0*i/image2.cols+v*1.0*j/image2.rows));
                    //sum=s
                }
            }
            //cout << u << " " << v << " " << int(sum) << endl;
            if (sum>=255) sum=255;
            transformDFT.at<uchar>(transformDFT.rows/2-v,transformDFT.cols/2-u)=sum;
            sum=0.0;
        }
    }
    imshow("DFT", transformDFT);
}
