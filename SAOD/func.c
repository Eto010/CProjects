#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "func.h"

int ctrlSum(int arr[], int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
        k += arr[i];
    return k;
}

int lineCount(int arr[], int n)
{
    int k = 0;
    for (int i = 1; i < n; i++)
        if (arr[i - 1] > arr[i])
            k++;

    return k + 1;
}
int *masGenLow(int x)
{
    int *arrIn = malloc(x * sizeof *arrIn);
    if (!arrIn) return NULL;

    for (int i = x - 1; i >= 0; i--) {
        arrIn[i] =  x - i;
    }

    return arrIn;
}

int *masGenHigh(int x)
{
    int *arrIn = malloc(x * sizeof *arrIn);
    if (!arrIn) return NULL;

    for (int i = 0; i < x; i++) {
        arrIn[i] = i;
    }

    return arrIn;
}

int *masGenRand(int x)
{
    int *arrIn = malloc(x * sizeof *arrIn);
    if (!arrIn) return NULL;

    for (int i = 0; i < x; i++) {
        arrIn[i] = 1 + rand() % x; 
    }

    return arrIn;
}

int *divSearch(int n)
{
    float nd = (float)n; 
    float sqn = sqrtf(nd);
    int sq = (int)sqn + 1;
    int c = 0;
    for(int i = 1; i < sq; i++)
    {
        if (n % i == 0)
        {
            c++;
        }
    }
    int *arrIn = malloc((c + 1) * sizeof *arrIn);
    arrIn[0] = c;
    arrIn[c] = 1;
    c = 1;
    for(int i = sq; i > 1; i--)
    {
        if (n % i == 0)
        {
            arrIn[c] = i;
            c++;
        }
    }
    return arrIn;
}
int *knutSearch(int n)
{
    float nf = log2f((float)n);
    int log = (int)nf + 1;
    int c = 0; int hi = 0; int h = 1;
    while(hi < log)
    {
        hi = 2*h + 1;
        c++;
        h = hi;
    }
    int *arrIn = malloc((c + 1) * sizeof *arrIn);
    arrIn[0] = c;
    h = 1; hi = 0; c = 1;
    while(hi < log)
    {
        hi = 2*h + 1;
        arrIn[c] = hi;
        c++;
        h = hi;
    }
    int *arrRet = malloc((c + 2) * sizeof *arrIn);
    arrRet[0] = arrIn[0] + 1;
    arrRet[c] = 1;
    c = 1;
    for (int i = arrIn[0]; i > 0; i--)
    {
        arrRet[c] = arrIn[i];
        c++;
    }
    return arrRet;
}

void printArrayStr(int arr[])
{
    int c = arr[0];
    for(int i = 1; i <= c; i++){
        if (i != c)
        {
            printf("%d, ", arr[i]);
        }
        else
        {
            printf("%d", arr[i]);
        }
    }
}
int *masGenRandSort(int n)
{
    int *arrIn = malloc(n * sizeof *arrIn);
    if (!arrIn) return NULL;

    for (int i = 0; i < n; i++) {
        arrIn[i] = 1 + rand() % n; 
    }

    for (int i = 0; i < n - 1; i++)
    {
        int k = i;
        for (int j = i; j < n; j++)
        {
            if (arrIn[j] < arrIn[k])
            {
                k = j;
            }
        }
        int temp = arrIn[i];
        arrIn[i] = arrIn[k];
        arrIn[k] = temp;
    }
    return arrIn;
}