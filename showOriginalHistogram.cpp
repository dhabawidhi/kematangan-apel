#include "header.h"
void dhaba::showOriginalHistogram(int a[], Mat image2,int bin,int maks)
{
    int normal[256]={0};
    for(int i=0;i<256;i++)
    {
        normal[i]=round(a[i]*bin/maks);
        //cout << normal[i] << endl;
    }
    int kaliLebar=2;
    Mat hist=image2;
    hist.rows=bin;
    hist.cols=bin*kaliLebar+kaliLebar+1;
    int color=128;
    //cout << hist.cols << endl;

    for(int i=0;i<hist.cols+kaliLebar;i++)
    {
        //cout << i << " " << normal[i/kaliLebar] << endl;
        for(int j=0;j<hist.rows;j++)
        {
            if(j<hist.rows-normal[i/kaliLebar]) hist.at<uchar>(j,i)=0;
            else hist.at<uchar>(j,i)=char(color);
            //hist.at<uchar>(j,i)=0;
        }
    }
    imshow("Original Histogram",hist);
}
