#include <stdio.h>
#define LEN(x) (sizeof(x)/sizeof((x)[0]))
#include "func.h"

int bubbleSort(int arr[], int n)
{
    int sum = ctrlSum(arr, n);
    int lines = lineCount(arr, n);
    int c = 0;
    int m = 0;
    int arrIn[n];
    for(int i = 0; i < n; i++)
    {
        arrIn[i] = arr[i];
    }
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = n - 1; j > i; j--)
        {
            c = c + 1;
            if (arrIn[j] < arrIn[j - 1])
            {
                m = m + 1;
                int temp = arrIn[j];
                arrIn[j] = arrIn[j - 1];
                m = m + 1;
                arrIn[j - 1] = temp;
                m = m + 1;
            }
        }
    }
    int x = c + m;
    if ((ctrlSum(arrIn, n) == sum) && (lineCount(arrIn, n) == 1))
    { 
        return x;
    }
}

int shakerSort(int arr[], int n)
{
   int arrIn[n];
   for(int i = 0; i < n; i++)
   {
    arrIn[i] = arr[i];
   } 
    int sum = ctrlSum(arr, n);
    int lines = lineCount(arr, n);
    int c = 0;
    int m = 0;
    int l = 0;
    int r = n - 1;
    int k = n;
    do
    {
        for(int i = r; i > l; i--)
        {
            c = c + 1;
            if (arrIn[i] < arrIn[i - 1])
            {
                m = m + 1;
                int temp = arrIn[i];
                m = m + 1;
                arrIn[i] = arrIn[i - 1];
                m = m + 1;
                arrIn[i - 1] = temp;
                k = i;
            }  
        }
        l = k;
        for(int j = l; j < r; j++)
        {
            c = c + 1;
            if (arrIn[j] > arrIn[j + 1])
            {
                m = m + 1;
                int temp = arrIn[j];
                m = m + 1;
                arrIn[j] = arrIn[j + 1];
                m = m + 1;
                arrIn[j + 1] = temp;
                k = j;
            }   
        }
        r = k;
    } while (l < r);
    if (sum == ctrlSum(arrIn, n) && lineCount(arrIn, n) == 1)
    {
        int x = c + m;
        return x;
    }
}

int main()
{
    int *arrLow1 = masGenLow(100);
    int *arrLow2 = masGenLow(200);
    int *arrLow3 = masGenLow(300);
    int *arrLow4 = masGenLow(400);
    int *arrLow5 = masGenLow(500);
    int *arrRand1 = masGenRand(100);
    int *arrRand2 = masGenRand(200);
    int *arrRand3 = masGenRand(300);
    int *arrRand4 = masGenRand(400);
    int *arrRand5 = masGenRand(500);
    int *arrHigh1 = masGenHigh(100);
    int *arrHigh2 = masGenHigh(200);
    int *arrHigh3 = masGenHigh(300);
    int *arrHigh4 = masGenHigh(400);
    int *arrHigh5 = masGenHigh(500);
    printf(" N | Мфакт+Сфакт пузырьковой  | Мф+Сф шейкерной \n");
    printf("   | Убыв.  | Случ.  | Возр.  | Убыв.  | Случ.  | Возр.     \n");
    printf("100| %d  | %d  | %d   | %d  | %d  | %d\n", bubbleSort(arrLow1, 100), bubbleSort(arrRand1, 100), bubbleSort(arrHigh1, 100), shakerSort(arrLow1, 100), shakerSort(arrRand1, 100), shakerSort(arrHigh1, 100));
    printf("200| %d  | %d  | %d  | %d  | %d  | %d\n", bubbleSort(arrLow2, 200), bubbleSort(arrRand2, 200), bubbleSort(arrHigh2, 200), shakerSort(arrLow2, 200), shakerSort(arrRand2, 200), shakerSort(arrHigh2, 200));
    printf("300| %d | %d | %d  | %d | %d  | %d\n", bubbleSort(arrLow3, 300), bubbleSort(arrRand3, 300), bubbleSort(arrHigh3, 300), shakerSort(arrLow3, 300), shakerSort(arrRand3, 300), shakerSort(arrHigh3, 300));
    printf("400| %d | %d | %d  | %d | %d | %d\n", bubbleSort(arrLow4, 400), bubbleSort(arrRand4, 400), bubbleSort(arrHigh4, 400), shakerSort(arrLow4, 400), shakerSort(arrRand4, 400), shakerSort(arrHigh4, 400));
    printf("500| %d | %d | %d | %d | %d | %d\n", bubbleSort(arrLow5, 500), bubbleSort(arrRand5, 500), bubbleSort(arrHigh5, 500), shakerSort(arrLow5, 500), shakerSort(arrRand5, 500), shakerSort(arrHigh5, 500));
}