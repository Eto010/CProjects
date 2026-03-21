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
    int mc1 = (100 * 100 - 100) / 2 * 4;
    int mc2 = (200 * 200 - 200) / 2 * 4;
    int mc3 = (300 * 300 - 300) / 2 * 4;
    int mc4 = (400 * 400 - 400) / 2 * 4;
    int mc5 = (500 * 500 - 500) / 2 * 4;
    printf(" N | M+Cтеоретич. | Мфакт+Сфакт               \n");
    printf("   |              | Убыв. | Случ. | Возр.     \n");
    printf("100| %d        |%d   | %d  | %d \n", mc1, bubbleSort(arrLow1, 100), bubbleSort(arrRand1, 100), bubbleSort(arrHigh1, 100));
    printf("200| %d        |%d   | %d  | %d \n", mc2, bubbleSort(arrLow2, 200), bubbleSort(arrRand2, 200), bubbleSort(arrHigh2, 200));
    printf("300| %d       |%d   | %d  | %d \n", mc3, bubbleSort(arrLow3, 300), bubbleSort(arrRand3, 300), bubbleSort(arrHigh3, 300));
    printf("400| %d       |%d   | %d  | %d \n", mc4, bubbleSort(arrLow4, 400), bubbleSort(arrRand4, 400), bubbleSort(arrHigh4, 400));
    printf("500| %d       |%d   | %d  | %d \n", mc5, bubbleSort(arrLow5, 500), bubbleSort(arrRand5, 500), bubbleSort(arrHigh5, 500));
}