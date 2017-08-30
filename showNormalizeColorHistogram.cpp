#include "header.h"
void dhaba::showNormalizeColorHistogram(int g[], int b[], int r[],int bin,Mat image)
{
    int totalPixel=image.rows*image.cols-g[0];
    double normal[256]={0};
    double maks=0;
    for(int i=1;i<256;i++)
    {
        normal[i]=b[i]*1.0/totalPixel;
        if(normal[i]>=maks) maks=normal[i];
        //cout << normal[i] << endl;
//        cout << normal[i] << endl;
    }
    int show[256]={0};
    int row=255;
    for(int i=1;i<256;i++)
    {
        show[i]=round(normal[i]*row/maks);
        cout << show[i] << endl;
    }
    int kaliLebar=2;
    Mat hist(image.rows,image.cols,image.type(),Scalar(0,0,0));
    hist.rows=row;
    hist.cols=row*kaliLebar+kaliLebar+1;
    int color=128;
    //cout << hist.cols << endl;

    for(int i=0;i<hist.cols+kaliLebar;i++)
    {
        cout << i << " " << show[i/kaliLebar] << endl;
        for(int j=0;j<hist.rows;j++)
        {
            if(j<hist.rows-show[i/kaliLebar]) {hist.at<Vec3b>(j,i)[0]=0; hist.at<Vec3b>(j,i)[1]=0;hist.at<Vec3b>(j,i)[2]=0;}
            else {hist.at<Vec3b>(j,i)[0]=128; hist.at<Vec3b>(j,i)[1]=char(0);hist.at<Vec3b>(j,i)[2]=char(0);}
            //hist.at<uchar>(j,i)=0;
        }
    }
    imshow("Original Histogram",hist);
}
