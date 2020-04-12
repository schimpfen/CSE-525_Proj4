#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matrixInit(int *ptrMatrix, int numRows, int numCols);
int matrixSumRM(int *ptrMatrix, int numRows, int numCols);
int matrixSumCM(int *ptrMatrix, int numRows, int numCols);

int main()
{
    srand(time(NULL));
    
    int m20x20[20][20];
    int m200x200[200][200];
    int m2000x2000[2000][2000];
    int *ptrMat20 = &m20x20[0][0];
    int *ptrMat200 = &m200x200[0][0];
    int *ptrMat2000 = &m2000x2000[0][0];
    int sum20x20;
    int sum200x200;
    int sum2000x2000;
    clock_t cStart20R, cEnd20R, cStart20C, cEnd20C;
    clock_t cStart200R, cEnd200R, cStart200C, cEnd200C;
    clock_t cStart2000R, cEnd2000R, cStart2000C, cEnd2000C;
    clock_t cDur20, cDur200, cDur2000;
    //add timestamps for each matrix sum
    
    matrixInit(ptrMat20,20,20);
    matrixInit(ptrMat200,200,200);
    matrixInit(ptrMat2000,2000,2000);
    
    //timing for each Row-Major Summation
    cStart20R = clock();
    sum20x20 = matrixSumRM(ptrMat20,20,20);
    cEnd20R = clock();
    cStart200R = clock();
    sum200x200 = matrixSumRM(ptrMat200,200,200);
    cEnd200R = clock();
    cStart2000R = clock();
    sum2000x2000 = matrixSumRM(ptrMat2000,2000,2000);
    cEnd2000R = clock();
    
    cDur20 = cEnd20R - cStart20R;
    cDur200 = cEnd200R - cStart200R;
    cDur2000 = cEnd2000R - cStart2000R;
    printf("Row Major, 20x20: %ld\n",cDur20);
    printf("Row Major, 200x200: %ld\n",cDur200);
    printf("Row Major, 2000x2000: %ld\n",cDur2000);
    
    //timing for each Column-Major Summation
    cStart20C = clock();
    sum20x20 = matrixSumCM(ptrMat20,20,20);
    cEnd20C = clock();
    cStart200C = clock();
    sum200x200 = matrixSumCM(ptrMat200,200,200);
    cEnd200C = clock();
    cStart2000C = clock();
    sum2000x2000 = matrixSumCM(ptrMat2000,2000,2000);
    cEnd2000C = clock();
    
    cDur20 = cEnd20C - cStart20C;
    cDur200 = cEnd200C - cStart200C;
    cDur2000 = cEnd2000C - cStart2000C;
    printf("Column Major, 20x20: %ld\n",cDur20);
    printf("Column Major, 200x200: %ld\n",cDur200);
    printf("Column Major, 2000x2000: %ld\n",cDur2000);
    
}

void matrixInit(int *ptrMatrix, int numRows, int numCols)
{
    for(int i=0;i<numRows;i++)
    {
        for(int j=0;j<numCols;j++)
        {
                ptrMatrix[i*numCols+j]= rand();
        }
    }
}

int matrixSumRM(int *ptrMatrix, int numRows, int numCols)
{
    int sum = 0;
    for(int i=0;i<numRows;i++)
    {
        for(int j=0;j<numCols;j++)
        {
                sum += ptrMatrix[i*numCols+j];
        }
    }
}

int matrixSumCM(int *ptrMatrix, int numRows, int numCols)
{
    int sum = 0;
    for(int j=0;j<numCols;j++)
    {
        for(int i=0;i<numRows;i++)
        {
                sum += ptrMatrix[i*numCols+j];
        }
    }
}
