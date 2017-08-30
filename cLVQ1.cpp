// Filename: "cLVQ1.cpp"

#include "globals.h"
#include "cLVQ1.h"

cLVQ1::cLVQ1(int tPatterns[T_PATTERNS][VEC_LEN], int targets[T_PATTERNS])
{
    DECAY_RATE = 0.99;                  //About 100 iterations.
    MIN_ALPHA = 0.01;
    RADIUS_REDUCTION_POINT = 0.023;     //Last 20% of iterations.

    d = NULL;
    d = new double[N_CLUSTERS];         //Network nodes.

    w = NULL;                           //Weight matrix.
    w = new double*[N_CLUSTERS];
    for(int i = 0; i < N_CLUSTERS; i++)
    {
        w[i] = new double[VEC_LEN];
    }

    mPattern = NULL;                    //Training patterns.
    mPattern = new int*[T_PATTERNS];
    for(int i = 0; i < T_PATTERNS; i++) //mPattern = tPatterns
    {
        mPattern[i] = new int[VEC_LEN];
        for(int j = 0; j < VEC_LEN; j++)
        {
            mPattern[i][j] = tPatterns[i][j];
        } // j
    } // i

    mTarget = NULL;
    mTarget = new int[T_PATTERNS];
    for(int i = 0; i < T_PATTERNS; i++) //mTarget = targets
    {
        mTarget[i] = targets[i];
    } // i

    alpha = 0.6;
    mReductionPoint = 0;

    return;
}

cLVQ1::~cLVQ1()
{
    // Release any allocated memory to OS.
    if(d != NULL){
        delete [] d;
    }
    if(w != NULL){
        for(int i = 0; i < N_CLUSTERS; i++)
        {
            delete [] w[i];
        } // i
        delete [] w;
    }
    if(mPattern != NULL){
        for(int i = 0; i < T_PATTERNS; i++)
        {
            delete [] mPattern[i];
        } // i
        delete [] mPattern;
    }
    if(mTarget != NULL){
        delete [] mTarget;
    }

    return;
}

void cLVQ1::initializeWeights(int clusterNumber, int tPattern[VEC_LEN])
{
//clusterNumber = the output node (cluster) to assign the pattern to.
//tPattern = the pattern which the output node will respond to.

    //Initialize weights.
    for(int i = 0; i < VEC_LEN; i++)
    {
        w[clusterNumber][i] = static_cast<double>(tPattern[i]);
    } // i

    return;
}

void cLVQ1::trainNetwork()
{
    bool reductionFlag = false;
    int dMin;

    mIterations = 0;

    do
    {
        mIterations += 1;

        for(int VecNum = 0; VecNum < T_PATTERNS; VecNum++)
        {
            //Compute input for all nodes.
            computeInput(mPattern, VecNum);

            //See which is smaller?
            dMin = minimum(d);

            //Update the weights on the winning unit.
            updateWeights(VecNum, dMin);

        } // VecNum

        //Reduce the learning rate.
        alpha = DECAY_RATE * alpha;

        //Reduce radius at specified point.
        if(alpha < RADIUS_REDUCTION_POINT){
            if(reductionFlag == false){
                reductionFlag = true;
                mReductionPoint = mIterations;
            }
        }
    } while(alpha > MIN_ALPHA);

    return;
}

int cLVQ1::iterations() const
{
    return mIterations;
}

int cLVQ1::reductionPoint() const
{
    return mReductionPoint;
}

void cLVQ1::patterns(int retArray[T_PATTERNS][VEC_LEN])
{
    for(int i = 0; i < T_PATTERNS; i++)
    {
        for(int j = 0; j < VEC_LEN; j++)
        {
            retArray[i][j] = mPattern[i][j];
        } // j
    } // i
}

void cLVQ1::weights(double retArray[T_PATTERNS][VEC_LEN])
{
    for(int i = 0; i < T_PATTERNS; i++)
    {
        for(int j = 0; j < VEC_LEN; j++)
        {
            retArray[i][j] = w[i][j];
        } // j
    } // i
}

int cLVQ1::getCluster(int inputPattern[VEC_LEN])
{
    //Compute input for all nodes.
    computeInput(inputPattern);

    //See which is smaller?
    return minimum(d);

}

void cLVQ1::updateWeights(int vectorNumber, int dMin)
{
    for(int i = 0; i < VEC_LEN; i++)
    {
        //Update the winner.
        if(dMin == mTarget[vectorNumber]){
            w[dMin][i] += (alpha * (mPattern[vectorNumber][i] - w[dMin][i]));
        }else{
            w[dMin][i] -= (alpha * (mPattern[vectorNumber][i] - w[dMin][i]));
        }
    } // i

}

void cLVQ1::computeInput(int **vectorArray, int vectorNumber)
{
//Overloaded function.  See ComputeInput below.
    clearArray(d);
    for(int i = 0; i < N_CLUSTERS; i++)
    {
        for(int j = 0; j < VEC_LEN; j++)
        {
            d[i] += pow((w[i][j] - vectorArray[vectorNumber][j]), 2);
        } // j
    } // i

}

void cLVQ1::computeInput(int vectorArray[VEC_LEN])
{
//Overloaded function.  See ComputeInput above.
    clearArray(d);
    for(int i = 0; i < N_CLUSTERS; i++)
    {
        for(int j = 0; j < VEC_LEN; j++)
        {
            d[i] += pow((w[i][j] - vectorArray[j]), 2);
        } // j
    } // i

}

void cLVQ1::clearArray(double anArray[N_CLUSTERS])
{
    for(int i = 0; i < N_CLUSTERS; i++)
    {
        anArray[i] = 0.0;
    } // i

}

int cLVQ1::minimum(double nodeArray[N_CLUSTERS])
{
    int winner;
    bool foundNewWinner;
    bool done = false;

    winner = 0;
    do
    {
        foundNewWinner = false;
        for(int i = 0; i < N_CLUSTERS; i++)
        {
            if(i != winner){             //Avoid self-comparison.
                if(nodeArray[i] < nodeArray[winner]){
                    winner = i;
                    foundNewWinner = true;
                }
            }
        } // i

        if(foundNewWinner == false){
            done = true;
        }
    } while(!done);

    return winner;

}

