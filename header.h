#include <iostream>
#include <string>
#include <cv.h>
#include <highgui.h>
#include <cxcore.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <sstream>
#include <math.h>
#include <vector>
#include "cLVQ1.h"
using namespace std;
using namespace cv;

struct my_colour_array
{
    unsigned int colours[3];

// initialising constructor
    my_colour_array (unsigned int r, unsigned int g, unsigned int b)
    {
        this->colours[0] = r;
        this->colours[1] = g;
        this->colours[2] = b;
    }
};


class dhaba{

    public: void gausian(Mat image, int kernel);
    public: Mat grayscale(Mat image);
    public: void rataan(Mat image);
    public: void laplaceGausian(Mat image);
    public: void imageThresholding(Mat image);
    public: void imageNegatif(Mat image);
    public: void contractStretching(Mat image);
    public: void imageSubtraction(Mat image, Mat image2);
    public: void oriHistogram(Mat image);
    public: void showHistogram(Mat image);
    public: void showOriginalHistogram(int a[],Mat image2,int bin,int maks);
    public: void showNormalizeHistogram(int totalPixel, int a[],int bin,Mat image2);
    public: void showAkumulasiHistogram(int totalPixel, int a[],int bin,Mat image2);
    public: void showEqualizedHistogram(int totalPixel, int a[],int bin,Mat image2,int maksimum);
    public: void DFT(Mat image);
    public: void DFTOpenCV();
    public: void yCbCr(Mat image);
    public: Mat detection(Mat edge,Mat ori);
    public: Mat cutImage(Mat threshold, Mat image);
    public: vector < vector <int> > CalcColorHistogram(Mat image);
    public: void showNormalizeColorHistogram(int b[], int g[], int r[],int bin,Mat image);
    public: void showColorHistogram(Mat image, string nama);
    public: void CalcRipe(Mat image, Mat image2);

};




