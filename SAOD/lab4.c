#include <stdio.h>
#include "func.h"

int insertSort(int arr[], int n)
{
    int sum = ctrlSum(arr, n);
    int arrIn[n];
    int c= 0;
    int m = 0;
   for(int i = 0; i < n; i++)
   {
    arrIn[i] = arr[i];
   } 
    for (int i = 1; i < n; i++)
    {
        int t = arrIn[i];
        int j = i - 1;
        while((j > -1) && (t < arrIn[j]))
        {
            c++;
            arrIn[j + 1] = arrIn[j];
            m++;
            j = j - 1;
        }
        arrIn[j + 1] = t;
        m++;
    }
    if (sum == ctrlSum(arrIn, n) && lineCount(arrIn, n) == 1)
    {
        int x = c + m;
        printf("%d + %d = %d\n", c, m, x);
    }
    else{
        printf("ERROR\n");
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
    printf("InsertSort: \n For 100 elements: \n High: \n" );
    insertSort(arrHigh1, 100);
    printf("Rand:\n");
    insertSort(arrRand1, 100);
    printf("Low: \n");
    insertSort(arrLow1, 100);
    printf("For 200 elements: \n High: \n" );
    insertSort(arrHigh2, 200);
    printf("Rand:\n");
    insertSort(arrRand2, 200);
    printf("Low: \n");
    insertSort(arrLow2, 200);
    printf("For 300 elements: \n High: \n" );
    insertSort(arrHigh3, 300);
    printf("Rand:\n");
    insertSort(arrRand3, 300);
    printf("Low: \n");
    insertSort(arrLow3, 300);
    printf("For 400 elements: \nHigh: \n" );
    insertSort(arrHigh4, 400);
    printf("Rand:\n");
    insertSort(arrRand4, 400);
    printf("Low: \n");
    insertSort(arrLow4, 400);
    printf("\n For 500 elements: \nHigh: \n" );
    insertSort(arrHigh5, 500);
    printf("Rand:\n");
    insertSort(arrRand5, 500);
    printf("Low: \n");
    insertSort(arrLow5, 500);
}