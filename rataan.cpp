#include "header.h"
void dhaba::rataan(Mat image)
{
    Mat image2=grayscale(image);
    int sum=0,temp=0,c=0;
    for(int i=0;i<image2.rows; i++)
    {
        for (int j=0;j<image2.cols;j++)
        {
            /*if(i==0&&j==0) image2.at<uchar>(i,j)=(image2.at<uchar>(0,0)+image2.at<uchar>(1,0)+image2.at<uchar>(0,1)+image2.at<uchar>(1,1))/4;
            else if(i==0&&j!=image2.cols-1) image2.at<uchar>(i,j)=(image2.at<uchar>(i,j-1)+image2.at<uchar>(i,j)+image2.at<uchar>(i,j+1)+image2.at<uchar>(i+1,j-1)+image2.at<uchar>(i+1,j)+image2.at<uchar>(i+1,j+1))/6;
            else if(i==0&&j==image2.cols-1) image2.at<uchar>(i,j)=(image2.at<uchar>(i,j-1)+image2.at<uchar>(i,j)+image2.at<uchar>(i+1,j-1)+image2.at<uchar>(i+1,j))/4;
            else if(i>0&&i<image2.rows-1&&j==0) image2.at<uchar>(i,j)=(image2.at<uchar>(i-1,j)+image2.at<uchar>(i-1,j+1)+image2.at<uchar>(i,j)+image2.at<uchar>(i,j+1)+image2.at<uchar>(i+1,j)+image2.at<uchar>(i+1,j+1))/6;
            else if(i>0&&i<image2.rows-1) image2.at<uchar>(i,j)=(image2.at<uchar>(i-1,j-1)+image2.at<uchar>(i-1,j)+image2.at<uchar>(i-1,j+1)+image2.at<uchar>(i,j-1)+image2.at<uchar>(i,j)+image2.at<uchar>(i,j+1)+image2.at<uchar>(i+1,j-1)+image2.at<uchar>(i+1,j)+image2.at<uchar>(i+1,j+1))/9;
            else if(i>0&&i<image2.rows-1&&j==image2.cols-1) image2.at<uchar>(i,j)=(image2.at<uchar>(i-1,j-1)+image2.at<uchar>(i-1,j)+image2.at<uchar>(i,j-1)+image2.at<uchar>(i,j)+image2.at<uchar>(i+1,j-1)+image2.at<uchar>(i+1,j))/6;
            else if(i==image.rows-1&&j==0) image2.at<uchar>(i,j)=(image2.at<uchar>(i-1,j)+image2.at<uchar>(i-1,j+1)+image2.at<uchar>(i,j)+image2.at<uchar>(i,j+1))/4;
            else if(i==image.rows-1&&j==image.cols-1) image2.at<uchar>(i,j)=(image2.at<uchar>(i-1,j-1)+image2.at<uchar>(i-1,j)+image2.at<uchar>(i,j-1)+image2.at<uchar>(i,j))/4;
            else image2.at<uchar>(i,j)=(image2.at<uchar>(i-1,j-1)+image2.at<uchar>(i-1,j)+image2.at<uchar>(i-1,j+1)+image2.at<uchar>(i,j-1)+image2.at<uchar>(i,j)+image2.at<uchar>(i,j+1))/6;
            */
            for(int gi=-1;gi<2;gi++)
            {
                for(int gj=-1;gj<2;gj++)
                {

                    if(i-gi>=0&&j-gj>=0)
                    {
                        //cout << image2.at<uchar>(i-gi,j-gj)*g[gi+3][gj+3] << endl;
                        sum=sum+image2.at<uchar>(i-gi,j-gj);
                        c++;
                    }
                }
                //if(sum==0) break;
                //temp=temp/sum;
            }
            //if(c==0) c=sum;

            temp=sum/c;

            //cout << sum << " " << temp << endl;
            c=0;
            sum=0;
            image2.at<uchar>(i,j)=char(temp);
        }
    }


    imshow("Rataan",image2);
}
