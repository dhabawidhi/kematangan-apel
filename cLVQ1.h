// Filename: "cLVQ1.h"

#ifndef CLVQ1_H
#define CLVQ1_H

#include "globals.h"
using namespace std;

const int N_CLUSTERS = 2;   // Number of clusters.
const int VEC_LEN = 3;     // Input pattern length.
const int T_PATTERNS = 16;  // Number of training patterns.


class cLVQ1
{

private:
    double DECAY_RATE;              //About 100 iterations.
    double MIN_ALPHA;
    double RADIUS_REDUCTION_POINT;  //Last 20% of iterations.

    double alpha;
    double * d;                     //Network nodes. The "clusters"

    int mIterations;
    int mReductionPoint;

    double **w;                     //Weight matrix.

    int **mPattern;                 //Training patterns.
    int * mTarget;

    void updateWeights(int vectorNumber, int dMin);
    void computeInput(int **vectorArray, int vectorNumber);
    void computeInput(int vectorArray[VEC_LEN]);
    void clearArray(double anArray[N_CLUSTERS]);
    int  minimum(double nodeArray[N_CLUSTERS]);

public:
    cLVQ1(int tPatterns[T_PATTERNS][VEC_LEN], int targets[T_PATTERNS]);
    ~cLVQ1();
    void trainNetwork();
    void initializeWeights(int clusterNumber, int tPattern[VEC_LEN]);
    int  iterations() const;
    int  reductionPoint() const;
    void patterns(int retArray[T_PATTERNS][VEC_LEN]);
    void weights(double retArray[T_PATTERNS][VEC_LEN]);
    int  getCluster(int inputPattern[VEC_LEN]);

}; // end cLVQ1 class.

#endif

