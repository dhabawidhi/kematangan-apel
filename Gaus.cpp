//#include "grayscale.h"
#include "header.h"
void dhaba::gausian(Mat image, int kernel)
{
    //cout << "repot" << endl;


    Mat image2=grayscale(image);
    int n;
    string nama;
    int a[50];
    if(kernel==7)
    {
        int a[]={0,0,0,5,0,0,0,0,5,18,32,18,5,0,0,18,64,100,64,18,0,5,32,100,100,100,32,5,0,18,64,100,64,18,0,0,5,18,32,18,5,0,0,0,0,5,0,0,0};
        n=kernel;
        cout << "kernel = 7" << endl;
    }
    else if(kernel==3)
    {
        int a[]={1,2,1,2,4,2,1,2,1};
        n=kernel;
        cout << "kernel = 3" << endl;
    }
    string jumlahkernel;
    stringstream data;
    data << n;
    data >> jumlahkernel;
    nama="Gaussian" + jumlahkernel +"x" +jumlahkernel;
    int g[n][n];
    int temp=0,sum=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<n;j++)
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
            for(int gi=-(n/2);gi<n/2+1;gi++)
            {
                for(int gj=-(n/2);gj<n/2+1;gj++)
                {

                    if(i-gi>=0&&j-gj>=0)
                    {
                        //cout << image2.at<uchar>(i-gi,j-gj)*g[gi+3][gj+3] << endl;
                        gaus7x7=gaus7x7+image2.at<uchar>(i-gi,j-gj)*g[gi+(n/2)][gj+(n/2)];
                        sum=sum+g[gi+(n/2)][gj+(n/2)];
                    }
                }
                //if(sum==0) break;
                //temp=temp/sum;
            }
            //if(c==0) c=sum;

            temp=gaus7x7/sum;

            //cout << sum << " " << temp << endl;
            gaus7x7=0;
            c=0;
            sum=0;
            image2.at<uchar>(i,j)=char(temp);
        }
    }
    imshow(nama.c_str(),image2);

}
