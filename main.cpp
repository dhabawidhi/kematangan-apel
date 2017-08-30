/*
Nama : Dhaba Widhikari
NIM: G64130051
*/
#include "header.h"
#include "globals.h"
#include "cLVQ1.h"
int DELAY_CAPTION = 1500;
int DELAY_BLUR = 100;
int MAX_KERNEL_LENGTH = 100;

Mat src; Mat dst; Mat dst2; Mat dstT; Mat dst2T; Mat srcT;
char window_name[] = "Filter Demo 1";

/// Function headers
int display_caption( char* caption );
int display_dst( int delay );

IplImage* MatToIplImage(Mat image)
{
    IplImage *img = new IplImage(image);
    return img;
}

Mat IplImageToMat(IplImage* image)
{
    Mat subImage(image);
    return subImage;
}

bool changeBool(bool input)
{
    if(input==TRUE) return FALSE;
    else return TRUE;
}

int main()
{
    cout << "Pra Proses" << endl;
    ///Training Matang
    string kelas, file;
    dhaba use;
    vector < vector <int> > Train2;
    vector <int> newRow;
    vector < vector <int> > Train;
    int forTrain[24][3];
    int c=0;
    for(int i=1;i<=1;i++)
    {
        for(int j=1;j<=8;j++)
        {
            stringstream data, data2;
            data << i;
            data >> kelas;
            data2 << j;
            data2 >> file;
            src = imread( "gambar/Latih/" + kelas + "/" + file +".jpg", 1 );
            if(!src.data){
                cout << "mage not loaded" << endl;
                return -1;
            }
            //imshow("original", src); // show original image

            ///convert to ipl image
            IplImage* img=new IplImage(src);

            ///RGB
            IplImage* R = cvCreateImage(cvGetSize(img), 8, 1);
            IplImage* G = cvCreateImage(cvGetSize(img), 8, 1);
            IplImage* B = cvCreateImage(cvGetSize(img), 8, 1);
            ///////////////////////////////////////////////////////
            IplImage* output1 = cvCreateImage(cvGetSize(img), 8, 1);
            IplImage* sub1 = cvCreateImage(cvGetSize(img), 8, 1);

            Mat median(img); // declare variable for median, convert ipl image to mat
            medianBlur(median,median, 19); // median blur 19 kernel
            //imshow("Median2", median);
            IplImage* hasilMedian=new IplImage(median); // convert mat to ipl image

            cvSplit(img,B,G,R,NULL); // split BGR color
            cvSub(R,G,sub1); // sub R G

            Mat sub2(sub1); // declare variable, convert ipl image to mat

            //cvCanny(img, img,0,255,3);

            medianBlur(sub2,dst, 25); // median blur 25 kernel

            //imshow("Median", dst);

            IplImage* sub3 = new IplImage(dst);

            //cvShowImage("coba",sub3);
            cvThreshold(sub3, output1,50, 255, CV_THRESH_BINARY);//thresholding process
            //cvShowImage("Threshold",output1);
            //
            Mat hasilPotongan=use.cutImage(output1,median); //cut image from 19 kernel
            //imshow("Hasil Potongan", hasilPotongan); // show cut image
            cvCanny(output1, output1,0,255,3);//untuk mendeteksi garis
            //cvShowImage("Edge Detection", output1);

            Train=use.CalcColorHistogram(hasilPotongan); // declare vector 2D
            IplImage* objek=MatToIplImage(output1); // convert mat to iplimage
            vector < vector <int> > Train2; // declare mat 2D
            //cvShowImage("IplImage Median", hasilMedian);
            //cvAdd(objek,hasilMedian,hasilMedian);
            //cvShowImage("Edge Detection dan Objek", hasilMedian);

            Mat edge(output1); // convert ipl image to mat
            Mat mat_ori(img); // convert ipl image to math

            //imshow("mat ori", mat_ori);
            Mat hasil=use.detection(edge, mat_ori); // detection

            forTrain[c][0]=Train[0][0];
            forTrain[c][1]=Train[0][1];
            forTrain[c][2]=Train[0][2];
            c++;
            cout << c << " " << forTrain[c-1][0] << " " << forTrain[c-1][1] << " " << forTrain[c-1][2] << endl;
        }
    }

    ///end training matang

    /// training mentah dan busuk

    for(int i=2;i<=2;i++)
    {
        for(int j=1;j<=8;j++)
        {
            stringstream data, data2;
            data << i;
            data >> kelas;
            data2 << j;
            data2 >> file;
            srcT = imread( "gambar/Latih/" + kelas + "/" + file +".jpg", 1 );
            if(!srcT.data){
                cout << "mage not loaded" << endl;
                return -1;
            }
            //imshow("original", src); // show original image

            ///convert to ipl image
            IplImage* imgT=new IplImage(srcT);

            ///RGB
            IplImage* RT = cvCreateImage(cvGetSize(imgT), 8, 1);
            IplImage* GT = cvCreateImage(cvGetSize(imgT), 8, 1);
            IplImage* BT = cvCreateImage(cvGetSize(imgT), 8, 1);
            ///////////////////////////////////////////////////////
            IplImage* output1T = cvCreateImage(cvGetSize(imgT), 8, 1);
            IplImage* sub1T = cvCreateImage(cvGetSize(imgT), 8, 1);
            IplImage* output2T = cvCreateImage(cvGetSize(imgT), 8, 1);
            IplImage* sub5T = cvCreateImage(cvGetSize(imgT), 8, 1);

            Mat medianT(imgT); // declare variable for median, convert ipl image to mat
            medianBlur(medianT,medianT, 19); // median blur 19 kernel
            //imshow("Median2", median);
            IplImage* hasilMedianT=new IplImage(medianT); // convert mat to ipl image

            cvSplit(imgT,BT,GT,RT,NULL); // split BGR color
            cvSub(RT,GT,sub1T); // sub R G
            cvSub(GT,BT, sub5T);

            Mat sub2T(sub1T); // declare variable, convert ipl image to mat
            Mat sub4T(sub5T);
            //cvCanny(img, img,0,255,3);

            medianBlur(sub2T,dstT, 25); // median blur 25 kernel
            medianBlur(sub4T, dst2T, 25); // median blur 25 kernel
            //imshow("Median", dst);

            IplImage* sub3T = new IplImage(dstT);
            IplImage* sub6T = new IplImage(dst2T);

            //cvShowImage("coba",sub3);
            cvThreshold(sub3T, output1T,50, 255, CV_THRESH_BINARY);//thresholding process
            cvThreshold(sub6T, output2T,50, 255, CV_THRESH_BINARY);//thresholding process
            //cvShowImage("Threshold",output1);
            //
            cvAdd(output1T, output2T, output1T, NULL);
            Mat hasilPotongan=use.cutImage(output1T,medianT); //cut image from 19 kernel
            //imshow("Hasil Potongan", hasilPotongan); // show cut image
            cvCanny(output1T, output1T,0,255,3);//untuk mendeteksi garis
            //cvShowImage("Edge Detection", output1);

            Train=use.CalcColorHistogram(hasilPotongan); // declare vector 2D
            IplImage* objek=MatToIplImage(output1T); // convert mat to iplimage

            Mat edgeT(output1T); // convert ipl image to mat
            Mat mat_oriT(imgT); // convert ipl image to math

            //imshow("mat ori", mat_ori);
            Mat hasilT=use.detection(edgeT, mat_oriT); // detection

            forTrain[c][0]=Train[0][0];
            forTrain[c][1]=Train[0][1];
            forTrain[c][2]=Train[0][2];
            c++;
            cout << c << " " << forTrain[c-1][0] << " " << forTrain[c-1][1] << " " << forTrain[c-1][2] << endl;
        }
    }
    /*
    ///LVQ Mateng Mentah Busuk
///Reverse Mateng Mentah Busuk
    int forTrainReverse[24][3];
    int cReverse=0;
    for(int i=0;i<3;i++)
        forTrainReverse[0][i]=forTrain[0][i];
    for(int i=1;i<8;i++)
    {
        cReverse=i*3;
        for(int j=0;j<3;j++)
        {
            forTrainReverse[cReverse][j]=forTrain[i][j];
        }
    }
    cReverse=0;
    int counter=1;
    for(int i=0;i<3;i++)
        forTrainReverse[1][i]=forTrain[8][i];
    for(int i=9;i<16;i++)
    {
        cReverse=counter*3+1;
        for(int j=0;j<3;j++)
        {
            forTrainReverse[cReverse][j]=forTrain[i][j];
        }
        counter++;
    }

    cReverse=0;
    counter = 1;
    for(int i=0;i<3;i++)
        forTrainReverse[2][i]=forTrain[16][i];
    for(int i=17;i<24;i++)
    {
        cReverse=counter*3+2;
        for(int j=0;j<3;j++)
        {
            forTrainReverse[cReverse][j]=forTrain[i][j];
        }
        counter++;
    }

    ///cout reverse matrix
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << forTrainReverse[i][j];
            if(j!=2) cout << " ";
            else cout << endl;
        }

    }
*/




//    char fontName[][4]={"Ma1", "Me1", "Bu1", "Ma2", "Me2", "Bu2","Ma3", "Me3", "Bu3",
//                        "Ma4", "Me4", "Bu4","Ma5", "Me5", "Bu5","Ma6", "Me6", "Bu6",
//                        "Ma7", "Me7", "Bu7","Ma8", "Me8", "Bu8"};


//    int target[24]={0,1,2,0,1,2,0,1,
//                    2,0,1,2,0,1,2,0,
//                    1,2,0,1,2,0,1,2};

//    cLVQ1 LVQ(forTrainReverse, target);
//    for(int i = 0; i < N_CLUSTERS; i++)
//    {
//        LVQ.initializeWeights(i, forTrainReverse[i]);
//        cout << "Weights for cluster " << i << " initialized to pattern "
//             << fontName[i] << endl;
//    } // i
//
//    LVQ.trainNetwork();
//
//    for(int i = 0; i < T_PATTERNS; i++)
//    {
//        cout << "Pattern " << fontName[i] << " belongs to cluster "
//             << LVQ.getCluster(forTrainReverse[i]) << endl;
//    }

    ///LVQ Mateng Mentah

    /// Mateng mentah
    int cReverse=0;
    int forTrainMM[16][3];
    for(int i=0;i<3;i++)
        forTrainMM[0][i]=forTrain[0][i];
    for(int i=1;i<8;i++)
    {
        cReverse=i*2;
        for(int j=0;j<3;j++)
        {
            forTrainMM[cReverse][j]=forTrain[i][j];
        }
    }
    cReverse=0;
    int counter=1;
    for(int i=0;i<3;i++)
        forTrainMM[1][i]=forTrain[8][i];
    for(int i=9;i<16;i++)
    {
        cReverse=counter*2+1;
        for(int j=0;j<3;j++)
        {
            forTrainMM[cReverse][j]=forTrain[i][j];
        }
        counter++;
    }
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << forTrainMM[i][j] ;
            if(j!=2) cout << " ";
            else cout << endl;
        }
    }

    char fontName[][4]={"Ma1", "Me1", "Ma2", "Me2","Ma3", "Me3",
                        "Ma4", "Me4","Ma5", "Me5","Ma6", "Me6",
                        "Ma7", "Me7","Ma8", "Me8"};

    int target[16]={0,1,0,1,0,1,
                    0,1,0,1,0,
                    1,0,1,0,1};
    //cout << forTrain[10][1] << endl;
    cout << "Klasifikasi dengan LVQ" << endl;
    cLVQ1 LVQ(forTrainMM, target);
    for(int i = 0; i < N_CLUSTERS; i++)
    {
        LVQ.initializeWeights(i, forTrainMM[i]);
        cout << "Weights for cluster " << i << " initialized to pattern "
             << fontName[i] << endl;
    } // i

    LVQ.trainNetwork();

    for(int i = 0; i < T_PATTERNS; i++)
    {
        cout << "Pattern " << fontName[i] << " belongs to cluster "
             << LVQ.getCluster(forTrainMM[i]) << endl;
    }


    ///Testing
    cout << "Testing" << endl;
    int forTest[1][3];
    for(int i=1;i<=1;i++)
    {
        for(int j=1;j<=1;j++)
        {
            int k;
            cout << "Masukkan Nama File :" ;
            cin >> k;
            stringstream data, data2;
            data << i;
            data >> kelas;
            data2 << k;
            data2 >> file;
            srcT = imread( "gambar/Uji/" + kelas + "/" + file +".jpg", 1 );
            if(!srcT.data){
                cout << "mage not loaded" << endl;
                return -1;
            }
            //imshow("original", srcT); // show original image

            ///convert to ipl image
            IplImage* imgT=new IplImage(srcT);

            ///RGB
            IplImage* RT = cvCreateImage(cvGetSize(imgT), 8, 1);
            IplImage* GT = cvCreateImage(cvGetSize(imgT), 8, 1);
            IplImage* BT = cvCreateImage(cvGetSize(imgT), 8, 1);
            ///////////////////////////////////////////////////////
            IplImage* output1T = cvCreateImage(cvGetSize(imgT), 8, 1);
            IplImage* sub1T = cvCreateImage(cvGetSize(imgT), 8, 1);
            IplImage* output2T = cvCreateImage(cvGetSize(imgT), 8, 1);
            IplImage* sub5T = cvCreateImage(cvGetSize(imgT), 8, 1);

            Mat medianT(imgT); // declare variable for median, convert ipl image to mat
            medianBlur(medianT,medianT, 19); // median blur 19 kernel
            //imshow("Median2", median);
            IplImage* hasilMedianT=new IplImage(medianT); // convert mat to ipl image

            cvSplit(imgT,BT,GT,RT,NULL); // split BGR color
            cvSub(RT,GT,sub1T); // sub R G
            cvSub(GT,BT, sub5T);

            Mat sub2T(sub1T); // declare variable, convert ipl image to mat
            Mat sub4T(sub5T);
            //cvCanny(img, img,0,255,3);

            medianBlur(sub2T,dstT, 25); // median blur 25 kernel
            medianBlur(sub4T, dst2T, 25); // median blur 25 kernel
            //imshow("Median", dst);

            IplImage* sub3T = new IplImage(dstT);
            IplImage* sub6T = new IplImage(dst2T);

            //cvShowImage("coba",sub3);
            cvThreshold(sub3T, output1T,50, 255, CV_THRESH_BINARY);//thresholding process
            cvThreshold(sub6T, output2T,50, 255, CV_THRESH_BINARY);//thresholding process
            //cvShowImage("Threshold",output1);
            //
            cvAdd(output1T, output2T, output1T, NULL);
            Mat hasilPotongan=use.cutImage(output1T,medianT); //cut image from 19 kernel
            imshow("Hasil Potongan", hasilPotongan); // show cut image
            cvCanny(output1T, output1T,0,255,3);//untuk mendeteksi garis
            //cvShowImage("Edge Detection", output1);

            Train=use.CalcColorHistogram(hasilPotongan); // declare vector 2D
            IplImage* objek=MatToIplImage(output1T); // convert mat to iplimage

            Mat edgeT(output1T); // convert ipl image to mat
            Mat mat_oriT(imgT); // convert ipl image to math

            //imshow("mat ori", mat_ori);
            Mat hasilT=use.detection(edgeT, mat_oriT); // detection

            forTest[c][0]=Train[0][0];
            forTest[c][1]=Train[0][1];
            forTest[c][2]=Train[0][2];
            c++;
            cout << forTest[c-1][0] << " " << forTest[c-1][1] << " " << forTest[c-1][2] << endl;
        }
    }
    int coba = LVQ.getCluster(forTrainMM[0]);
    cout << coba << endl;
    if(coba == 0) cout << "Hasil mateng" << endl;
    else cout << "Hasil mentah" << endl;

    waitKey(0);
    return 0;
 }

 int display_caption( char* caption )
 {
   dst = Mat::zeros( src.size(), src.type() );
   putText( dst, caption,
            Point( src.cols/4, src.rows/2),
            CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255) );

   imshow( window_name, dst );
   int c = waitKey( DELAY_CAPTION );
   if( c >= 0 ) { return -1; }
   return 0;
  }

  int display_dst( int delay )
  {
    imshow( window_name, dst );
    int c = waitKey ( delay );
    if( c >= 0 ) { return -1; }
    return 0;
  }


