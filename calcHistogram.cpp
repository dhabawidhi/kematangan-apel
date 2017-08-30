#include "header.h"
void dhaba::oriHistogram(Mat image)
{
    Mat image2=grayscale(image);
    int bin=255;
    int a[bin]={0};
    int sum=0;
    int maks=0;
    for(int k=0;k<256;k++)
    {
        for(int i=0;i<image2.rows; i++)
        {
            for (int j=0;j<image2.cols;j++)
            {

                    if(image2.at<uchar>(i,j)==k) sum++;
                    a[k]=sum;
            }
        }
        //cout << k << " " << a[k] << endl;
        if(a[k]>=maks) maks=a[k];
        sum=0;
        //cout << a[k] << endl;
    }
    int totalPixel=image2.rows*image2.cols;
    //cout << "maksnya " << maks << endl;
    //showOriginalHistogram(a,image2,bin,maks);
    showNormalizeHistogram(totalPixel,a,bin,image2);
    //showAkumulasiHistogram(totalPixel,a,bin,image2);
    //showEqualizedHistogram(totalPixel,a,bin,image2,maks);

}
