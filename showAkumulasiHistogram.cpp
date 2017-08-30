#include "header.h"
void dhaba::showAkumulasiHistogram(int totalPixel, int a[],int bin,Mat image2)
{
    double normal[256]={0};
    double maks=0;
    for(int i=0;i<256;i++)
    {
        normal[i]=a[i]*1.0/totalPixel;
        if(normal[i]>=maks) maks=normal[i];
//        cout << normal[i] << endl;
    }
    int show[256]={0};
    for(int i=0;i<256;i++)
    {
        show[i]=round(normal[i]*bin/maks);
        //cout << show[i] << endl;
    }
    int akumulasi[256]={0};
    akumulasi[0]=show[0];
    for(int i=1;i<256;i++)
    {
        akumulasi[i]=akumulasi[i-1]+show[i];
    }
    cout << akumulasi[255] << endl;
    int akumulasiShow[256]={0};
    for(int i=0;i<256;i++)
    {
        akumulasiShow[i]=round(akumulasi[i]*bin/akumulasi[255]);
        //cout << i << " " << akumulasiShow[i] << endl;
    }
    int kaliLebar=2;
    Mat hist=image2;
    hist.rows=bin;
    hist.cols=bin*kaliLebar+kaliLebar+1;
    int color=128;

    for(int i=0;i<hist.cols+kaliLebar;i++)
    {
        //cout << i << " " << show[i/kaliLebar] << endl;
        for(int j=0;j<hist.rows;j++)
        {
            if(j<hist.rows-akumulasiShow[i/kaliLebar]) hist.at<uchar>(j,i)=0;
            else hist.at<uchar>(j,i)=char(color);
        }
    }
    imshow("Akumulasi Histogram",hist);

}
