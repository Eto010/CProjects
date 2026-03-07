#include <stdio.h>
#include <stdlib.h>
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