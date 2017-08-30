
#include "header.h"
void dhaba::CalcRipe(Mat image, Mat image2)
{
    int bin=255;
    int b[bin],g[bin],r[bin];
    int sum=0,blue=0, green=0,red=0;
    int maksB=0,maksG=0,maksR=0;
    for(int k=0;k<256;k++)
    {
        for(int y=0;y<image.rows; y++)
        {
            for (int x=0;x<image.cols;x++)
            {
                    if(image.at<Vec3b>(y,x)[0]==k) blue++;
                    b[k]=blue;
                    if(image.at<Vec3b>(y,x)[1]==k) green++;
                    g[k]=green;
                    if(image.at<Vec3b>(y,x)[2]==k) red++;
                    r[k]=red;
            }
        }
        //cout << k << " " << b[k]<< " " << g[k]<< " " << r[k] << endl;
        if(b[k]>=maksB) maksB=b[k];
        if(g[k]>=maksG) maksG=g[k];
        if(r[k]>=maksR) maksR=r[k];
        blue=0,green=0,red=0;
        //cout << a[k] << endl;
    }

    int bT[bin],gT[bin],rT[bin];
    int sumT=0,blueT=0, greenT=0,redT=0;
    int maksBT=0,maksGT=0,maksRT=0;
    for(int k=0;k<256;k++)
    {
        for(int y=0;y<image2.rows; y++)
        {
            for (int x=0;x<image2.cols;x++)
            {
                    if(image2.at<Vec3b>(y,x)[0]==k) blueT++;
                    bT[k]=blueT;
                    if(image2.at<Vec3b>(y,x)[1]==k) greenT++;
                    gT[k]=greenT;
                    if(image2.at<Vec3b>(y,x)[2]==k) redT++;
                    rT[k]=redT;
            }
        }
        //cout << k << " " << b[k]<< " " << g[k]<< " " << r[k] << endl;
        if(bT[k]>=maksBT) maksBT=bT[k];
        if(gT[k]>=maksGT) maksGT=gT[k];
        if(rT[k]>=maksRT) maksRT=rT[k];
        blueT=0,greenT=0,redT=0;
        //cout << a[k] << endl;
    }
    //int totalPixel=image.rows*image.cols;
    //cout << "maksnya " << maks << endl;
    //showOriginalHistogram(a,image2,bin,maks);

    //showNormalizeColorHistogram(b,g,r,bin,image);
    //showAkumulasiHistogram(totalPixel,a,bin,image2);
    //showEqualizedHistogram(totalPixel,a,bin,image2,maks);
    //imshow("image", image);
    //showHistogram(image);
    //showColorHistogram(image,"template");
}
