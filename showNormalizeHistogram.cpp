#include "header.h"
void dhaba::showNormalizeHistogram(int totalPixel, int a[],int bin,Mat image2)
{
    double normal[256]={0};
    double maks=0;
    for(int i=0;i<256;i++)
    {
        normal[i]=a[i]*1.0/totalPixel;
        if(normal[i]>=maks) maks=normal[i];
        cout << normal[i] << endl;
//        cout << normal[i] << endl;
    }
    int show[256]={0};
    for(int i=0;i<256;i++)
    {
        show[i]=round(normal[i]*64/maks);
        //cout << show[i] << endl;
    }
    int kaliLebar=2;
    Mat hist=image2;
    hist.rows=64;
    hist.cols=bin*kaliLebar+kaliLebar+1;
    int color=128;
    //cout << hist.cols << endl;

    for(int i=0;i<hist.cols+kaliLebar;i++)
    {
        //cout << i << " " << show[i/kaliLebar] << endl;
        for(int j=0;j<hist.rows;j++)
        {
            if(j<hist.rows-show[i/kaliLebar]) hist.at<uchar>(j,i)=0;
            else hist.at<uchar>(j,i)=char(color);
        }
    }
    imshow("Normalize Histogram",hist);

}
