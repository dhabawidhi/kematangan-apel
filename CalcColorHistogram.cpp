
#include "header.h"



vector < vector <int> > dhaba::CalcColorHistogram(Mat image)
{
    int bin=255;
    int b[bin],g[bin],r[bin];
    int blue=0, green=0,red=0;
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

        blue=0,green=0,red=0;
        //cout << a[k] << endl;
    }
    int sumBlue=0, sumRed=0, sumGreen=0;
    int cb=0,cg=0,cr=0;
    for(int k=1;k<256;k++)
    {

        if(b[k]!=0) { sumBlue=sumBlue+g[k];}
        if(g[k]!=0) { sumGreen=sumGreen+g[k];}
        if(r[k]!=0) { sumRed=sumRed+r[k];}
        //cout << k << " " << g[k] << " " << sumGreen <<   endl;
        if(maksB<=b[k]) {maksB=b[k]; cb=k;}
        if(maksG<=g[k]) {maksG=g[k]; cg=k;}
        if(maksR<=r[k]) {maksR=r[k]; cr=k;}
        //cout << k << " " << g[k] << " " <<  sumGreen << endl;
    }
    //cout << cb << " " << cg << " " << cr << endl;
    int totalPixel=image.rows*image.cols;
    //cout << "maksnya " << maks << endl;
    //showOriginalHistogram(a,image2,bin,maks);

    //showNormalizeColorHistogram(b,g,r,bin,image);
    //showAkumulasiHistogram(totalPixel,a,bin,image2);
    //showEqualizedHistogram(totalPixel,a,bin,image2,maks);
    //imshow("image", image);
    //showHistogram(image);
    //showColorHistogram(image,"template");
//    cout << maksB << " " << maksG << " " << maksR << endl;
//    cout << sumBlue << " " << sumGreen << " " << sumRed << endl;
//    double redColor=maksR*1.0/sumRed;
//    double blueColor=maksB*1.0/sumBlue;
//    double greenColor=maksG*1.0/sumGreen;
//    cout << blueColor << " " << greenColor << " " << redColor << endl;
//    int fixB=round(blueColor*100), fixG=round(greenColor*100), fixR=round(redColor*100);
    int fixB = cb, fixG=cg, fixR=cr;
    //cout << fixB << " " << fixG << " " << fixR << endl;
    vector < vector <int> > myvector;
    vector <int> newRow;
    myvector.push_back(newRow);
    myvector.at(0).push_back(fixB);
    myvector.at(0).push_back(fixG);
    myvector.at(0).push_back(fixR);
    //cout << myvector[0][0] << " " << myvector[0][1] << " " <<  myvector[0][2] <<   endl;
    return myvector;
}
