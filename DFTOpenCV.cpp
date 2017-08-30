#include "header.h"
//Rearrange the quadran of fourier image so that the origin is at the image center src *dst arrays of equal size & type
void cvShiftDFT(CvArr *src_arr)
{
    CvMat *tmp;
    CvMat q1stub, q2stub, q3stub, q4stub;
    CvMat *q1, *q2, *q3, *q4;
    CvSize size=cvGetSize(src_arr);
    int cx, cy;
    tmp = cvCreateMat(size.height/2, size.width/2, cvGetElemType(src_arr));
    cx = size.width/2;
    cy=size.height/2; // image center

    q1=cvGetSubRect(src_arr, &q1stub, cvRect(0,0,cx,cy));
    q2=cvGetSubRect(src_arr, &q2stub, cvRect(cx,0,cx,cy));
    q3=cvGetSubRect(src_arr, &q3stub, cvRect(cx,cy,cx,cy));
    q4=cvGetSubRect(src_arr, &q4stub, cvRect(0,cy,cx,cy));
    // shifting
    cvCopy(q3, tmp, 0);
    cvCopy(q1, q3, 0);
    cvCopy(tmp, q1, 0);
    cvCopy(q4, tmp, 0);
    cvCopy(q2,q4,0);
    cvCopy(tmp,q2,0);
}

void dhaba::DFTOpenCV()
{
    const char* filename="acasia_disease2.jpg";
    IplImage * im;

    IplImage * realInput;
    IplImage * imaginaryInput;
    IplImage * complexInput;
    int dft_M, dft_N;
    CvMat * dft_A, tmp;
    IplImage * image_re;
    IplImage * image_Im;
    double m, M;

    // manggil citra konversi grayscale
    im = cvLoadImage(filename, CV_LOAD_IMAGE_GRAYSCALE);
    cvNamedWindow("win");
    cvShowImage("win", im);

    realInput = cvCreateImage(cvGetSize(im), IPL_DEPTH_64F,1);
    imaginaryInput = cvCreateImage(cvGetSize(im),IPL_DEPTH_64F, 1);
    complexInput = cvCreateImage(cvGetSize(im),IPL_DEPTH_64F, 2);

    cvScale(im, realInput,1.0,0.0);
    cvZero(imaginaryInput);
    cvMerge(realInput, imaginaryInput,NULL,NULL,complexInput);

    // melakuan padding pada dft_A dengan 0:
    dft_M = cvGetOptimalDFTSize(im->height-1);
    dft_N=cvGetOptimalDFTSize(im->width-1);

    dft_A=cvCreateMat(dft_M, dft_N,CV_64FC2);
    image_re=cvCreateImage(cvSize(dft_N,dft_M),IPL_DEPTH_64F,1);
    image_Im=cvCreateImage(cvSize(dft_N,dft_M),IPL_DEPTH_64F,1);

    //copy A to dft_A and pad dft_Awith zeros
    cvGetSubRect(dft_A, &tmp, cvRect(0,0,im->width, im->height));
    cvCopy(complexInput, &tmp, NULL);

    if(dft_A->cols > im->width)
    {
        cvGetSubRect(dft_A, &tmp,cvRect(im->width,0,dft_A->cols-im->width,im->height));
        cvZero(&tmp);
    }

    // melakukan transformasi fourier 2D, dengan menggunakan transformasi flags
    cvDFT(dft_A, dft_A, CV_DXT_FORWARD,complexInput->height);

    // split fourier menjadi dua bagian real dan imaginary

    cvSplit(dft_A, image_re,image_Im,0,0);

    // menghitung magnitude pada spektrum  mag= sqrt(Re^2 +Im^2)

    // complex the magnitude of the spectrum Mag= sqrt(Re^2+Im^2
    cvPow(image_re, image_re,2.0);
    cvPow(image_Im, image_Im,2.0);
    cvAdd(image_re,image_Im,image_re,NULL);
    cvPow(image_re,image_re,0.5);
    //compute log(1+Mag

    cvAddS(image_re,cvScalarAll(1.0), image_re,NULL); // 1+mag
    cvLog(image_re,image_re); // log(1+mag

    // proses shifting untuk mengurutkan ulang kuadran2 pada fourier image sehinga titi asal(origin berada pada pusat citra
    cvShiftDFT(image_re);

    // mengambil nilai minimum dan maksimum global dan menampilkan citra hasil transformasi fourier
    cvMinMaxLoc(image_re, &m, &M, NULL,NULL, NULL);

    cvScale(image_re,image_re,1.0/(M-m),1.0*(-m)/(M-m));

    cvNamedWindow("DFT");
    cvShowImage("DFT", image_re);

    // for inverse
    cvDFT(dft_A, dft_A, CV_DXT_INVERSE, complexInput->height);
    cvNamedWindow("DFT_INVERSE");

    // split fourier in real and imaginary parts
    cvSplit(dft_A, image_re, image_Im, 0,0);

    // compute the magnitude of the spectrum mag = sqrt(re^2 +im^2

    cvPow(image_re,image_re,2.0);
    cvPow(image_Im,image_Im,2.0);
    cvAdd(image_re,image_Im, image_re, NULL);
    cvPow(image_re,image_re,0.5);

    // compute log(1+mag
    cvAddS(image_re, cvScalarAll(1.0), image_re, NULL); // 1+mag;
    cvLog(image_re, image_re); // log(1+mag

    cvMinMaxLoc(image_re, &m, &M, NULL, NULL, NULL);
    cvScale(image_re,image_re,1.0/(M-m), 1.0*(-m)/(M-m));
    cvShowImage("DFT_INVERSE", image_re);
}
