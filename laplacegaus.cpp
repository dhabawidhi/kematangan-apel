#include "header.h"

void dhaba::laplaceGausian(Mat image)
{
    Mat image2=grayscale(image);
    int g[3][3],a[]={-1,-1,-1,-1,8,-1,-1,-1,-1};
    int temp=0,sum=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0;j<3;j++)
        {
            g[i][j]=a[temp];
            //sum=sum+a[temp];
            cout << i << " " << j << " " << g[i][j]<< endl;
            temp++;
        }
    }

    temp=0;
    sum=0;
    int gaus7x7=0;
    int c=0;
    for(int i=0;i<image2.rows; i++)
    {
        for (int j=0;j<image2.cols;j++)
        {
            for(int gi=-1;gi<2;gi++)
            {
                for(int gj=-1;gj<2;gj++)
                {

                    if(i-gi>=0&&j-gj>=0)
                    {
                        gaus7x7=gaus7x7+image2.at<uchar>(i-gi,j-gj)*g[gi+1][gj+1];
                        sum=sum+image2.at<uchar>(i-gi,j-gj);
                        c=c+g[gi+1][gj+1];
                    }
                }
                //if(sum==0) break;
                //temp=temp/sum;
            }
            if(c==0) c=sum;
            temp=gaus7x7;
            //cout << sum << " " << temp << endl;
            gaus7x7=0;
            c=0;
            sum=0;
            image2.at<uchar>(i,j)=char(temp);
        }
    }
    imshow("Laplace Gaussian Masih Gagal",image2);
}
