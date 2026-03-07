#include <stdio.h>
#define LEN(x) (sizeof(x)/sizeof((x)[0]))
#include "func.h"

int selectSort(int arr[], int n)
{
    int arrIn[n];
    for (int i = 0; i < n; i++)
    {
        arrIn[i] = arr[i];
    }
    int sum = ctrlSum(arr, n);
    int lines = lineCount(arr, n);
    int c = 0;
    int m = 0;


    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = i; j < n; j++)
        {
            c = c  + 1;
            if (arrIn[j] < arrIn[k])
            {
                k = j;
            }
        }
        m = m + 1;
        int temp = arrIn[i];
        arrIn[i] = arrIn[k];
        arrIn[k] = temp;
        
    }

    if (sum == ctrlSum(arrIn, n) && lineCount(arrIn, n) == 1)
    {
        printf("\n%d, %d \n", c, m);
    }
}

int enhSelectSort(int arr[], int n)
{
    int arrIn[n];
    for (int i = 0; i < n; i++)
    {
        arrIn[i] = arr[i];
    }
    int sum = ctrlSum(arr, n);
    int lines = lineCount(arr, n);
    int c = 0;
    int m = 0;


    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = i; j < n; j++)
        {
            c = c  + 1;
            if (arrIn[j] < arrIn[k])
            {
                k = j;
            }
        }
        c = c + 1;
        if (i != k)
        {
            m = m + 1;
            int temp = arrIn[i];
            arrIn[i] = arrIn[k];
            arrIn[k] = temp;
        }
    }

    if (sum == ctrlSum(arrIn, n) && lineCount(arrIn, n) == 1)
    {
        printf("\n%d, %d \n", c, m);
    }
}

int main()
{
    int lowArrT[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int randArrT[] = {8, 4, 3, 9, 6, 7, 10, 5, 1, 2};
    int highArrT[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int lowArrH[] = {100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int randArrH[] = {71, 81, 35, 89, 27, 64, 42, 22, 90, 75, 36, 86, 13, 46, 11, 48, 91, 97, 78, 61, 21, 80, 16, 52, 95, 63, 14, 73, 45, 54, 40, 1, 34, 26, 84, 66, 15, 59, 19, 57, 68, 30, 44, 47, 87, 28, 98, 43, 71, 9, 24, 37, 6, 69, 29, 18, 76, 50, 7, 67, 4, 96, 85, 83, 60, 31, 93, 10, 100, 94, 8, 88, 17, 65, 20, 2, 3, 53, 62, 92, 12, 58, 5, 79, 39, 41, 25, 74, 23, 56, 8, 4, 3, 9, 6, 7, 10, 5, 1, 2};
    int highArrH[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};           
    printf("Select Sort: \n");
    printf("lowArrT: \n");
    selectSort(lowArrT, 10);
    printf("randArrT: \n");
    selectSort(randArrT, 10);
    printf("highArrT: \n");
    selectSort(highArrT, 10);
    printf("lowArrH: \n");
    selectSort(lowArrH, 100);
    printf("randArrH: \n");
    selectSort(randArrH, 100);
    printf("highArrH: \n");
    selectSort(highArrH, 100);
    printf("Enhanced Select Sort: \n");
    printf("lowArrT: \n");
    enhSelectSort(lowArrT, 10);
    printf("randArrT: \n");
    enhSelectSort(randArrT, 10);
    printf("highArrT: \n");
    enhSelectSort(highArrT, 10);
    printf("lowArrH: \n");
    enhSelectSort(lowArrH, 100);
    printf("randArrH: \n");
    enhSelectSort(randArrH, 100);
    printf("highArrH: \n");
    enhSelectSort(highArrH, 100);
    int *arrRand1 = masGenRand(100);
    int *arrRand2 = masGenRand(200);
    int *arrRand3 = masGenRand(300);
    int *arrRand4 = masGenRand(400);
    int *arrRand5 = masGenRand(500);
    printf("Select Sort: \n For 100 elements: \n" );
    selectSort(arrRand1, 100);
    printf("For 200 elements: \n" );
    selectSort(arrRand2, 200);
    printf("For 300 elements: \n" );
    selectSort(arrRand3, 300);
    printf("For 400 elements: \n" );
    selectSort(arrRand4, 400);
    printf("\n For 500 elements: \n" );
    selectSort(arrRand5, 500);
    return 0;
}