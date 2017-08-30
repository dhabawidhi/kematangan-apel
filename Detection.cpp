#include "header.h"
Mat dhaba::detection(Mat edge, Mat ori)
{
    for(int y = 0; y < ori.rows; y++)
    {
        uchar* edgePtr = edge.ptr<uchar>(y);
        Vec3b* imgPtr = ori.ptr<Vec3b>(y);
        for(int x = 0; x < ori.cols; x++)
        {
            if(edgePtr[x] != 0)
            {
                imgPtr[x][0] = 255;
                 imgPtr[x][1] = 255;
                  imgPtr[x][2] = 0;
            }
        }
    }

    /*
    Mat result=ori;
    result = Mat(ori.size(),ori.type(), 0.0);
    for(int y=0;y<edge.rows;y++)
    {
        uchar* edgePtr=edge.ptr<uchar>(y);
        Vec3b* imgPtr=ori.ptr<Vec3b>(y);
        bool deteksi=FALSE;
        for(int x=0;x<edge.cols;x++)
        {
            if(edgePtr[x]!=0&&edgePtr[x+1]==0)
            {
                deteksi=TRUE;
                //cout << y << " " << x << " " << deteksi << endl;
            }
            else if(deteksi==TRUE&&edgePtr[x-1]==0&&edgePtr[x]!=0)
            {
                deteksi=FALSE;
                cout << y << " " << x << " " << deteksi << endl;
            }
            if(deteksi==TRUE)
            {
                //result.at<uchar>(y,x)=ori.at<uchar>(y,x);
            }
        }
    }
    */
    return ori;
}
