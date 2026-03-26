#include <stdio.h>
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


    for (int i = 0; i < n - 1; i++)
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
        m = m + 1;
        arrIn[i] = arrIn[k];
        arrIn[k] = temp;
    }

    if (sum == ctrlSum(arrIn, n) && lineCount(arrIn, n) == 1)
    {
       return m + c;
    }
}

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
        c++;
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
        return x;
    }}

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
    int mc1 = (100 * 100 - 100) + 2 * 100 - 2;
    int mc2 = (200 * 200 - 200) + 2 * 200 - 2;
    int mc3 = (300 * 300 - 300) + 2 * 300 - 2;
    int mc4 = (400 * 400 - 400) + 2 * 400 - 2;
    int mc5 = (500 * 500 - 500) + 2 * 500 - 2;
    printf(" N | M+Cтеоретич. | Мфакт+Сфакт               \n");
    printf("   |              | Убыв. | Случ. | Возр.     \n");
    printf("100| %d        |%d  | %d  | %d \n", mc1, insertSort(arrLow1, 100), insertSort(arrRand1, 100), insertSort(arrHigh1, 100));
    printf("200| %d        |%d  | %d | %d \n", mc2, insertSort(arrLow2, 200), insertSort(arrRand2, 200), insertSort(arrHigh2, 200));
    printf("300| %d        |%d  | %d | %d \n", mc3, insertSort(arrLow3, 300), insertSort(arrRand3, 300), insertSort(arrHigh3, 300));
    printf("400| %d       |%d | %d | %d \n", mc4, insertSort(arrLow4, 400), insertSort(arrRand4, 400), insertSort(arrHigh4, 400));
    printf("500| %d       |%d | %d| %d \n", mc5, insertSort(arrLow5, 500), insertSort(arrRand5, 500), insertSort(arrHigh5, 500));
    printf("\n");
    printf(" N |               Мф+Сф\n");
    printf("   | Select  | Bubble | Shaker | Insert\n");
    printf("100|  %d   | %d  | %d  | %d\n", selectSort(arrRand1, 100), bubbleSort(arrRand1, 100), shakerSort(arrRand1, 100), insertSort(arrRand1, 100));
    printf("200| %d   | %d  | %d  | %d\n", selectSort(arrRand2, 200), bubbleSort(arrRand2, 200), shakerSort(arrRand2, 200), insertSort(arrRand2, 200));
    printf("300|  %d  | %d | %d  | %d\n", selectSort(arrRand3, 300), bubbleSort(arrRand3, 300), shakerSort(arrRand3, 300), insertSort(arrRand3, 300));
    printf("400|  %d  | %d | %d | %d\n", selectSort(arrRand4, 400), bubbleSort(arrRand4, 400), shakerSort(arrRand4, 400), insertSort(arrRand4, 400));
    printf("500| %d  | %d | %d | %d\n", selectSort(arrRand5, 500), bubbleSort(arrRand5, 500), shakerSort(arrRand5, 500), insertSort(arrRand5, 500));
}