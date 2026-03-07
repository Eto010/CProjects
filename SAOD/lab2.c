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
    for(int i = 0; i < n; i++)
    {
        for(int j = n - 1; j > 0; j--)
        {
            c = c + 1;
            if (arrIn[j] < arrIn[j - 1])
            {
                m = m + 1;
                int temp = arrIn[j];
                arrIn[j] = arrIn[j - 1];
                arrIn[j - 1] = temp;
            }
        }
    }
    int x = c + m;
    if ((ctrlSum(arrIn, n) == sum) && (lineCount(arrIn, n) == 1))
    { 
    printf("%d + %d = %d\n", c, m, x);
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
    printf("Bubble sort : \n For 100 elements: \n High: \n" );
    bubbleSort(arrHigh1, 100);
    printf("Rand:\n");
    bubbleSort(arrRand1, 100);
    printf("Low: \n");
    bubbleSort(arrLow1, 100);
    printf("For 200 elements: \n High: \n" );
    bubbleSort(arrHigh2, 200);
    printf("Rand:\n");
    bubbleSort(arrRand2, 200);
    printf("Low: \n");
    bubbleSort(arrLow2, 200);
    printf("For 300 elements: \n High: \n" );
    bubbleSort(arrHigh3, 300);
    printf("Rand:\n");
    bubbleSort(arrRand3, 300);
    printf("Low: \n");
    bubbleSort(arrLow3, 300);
    printf("For 400 elements: \nHigh: \n" );
    bubbleSort(arrHigh4, 400);
    printf("Rand:\n");
    bubbleSort(arrRand4, 400);
    printf("Low: \n");
    bubbleSort(arrLow4, 400);
    printf("\n For 500 elements: \nHigh: \n" );
    bubbleSort(arrHigh5, 500);
    printf("Rand:\n");
    bubbleSort(arrRand5, 500);
    printf("Low: \n");
    bubbleSort(arrLow5, 500);
}