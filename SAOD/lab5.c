//ShellSort
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include "func.h"

int shellSort(int arr[], int n)
{
    int arrIn[n];
    for (int i = 0; i < n; i++)
    {
        arrIn[i] = arr[i];
    }
    int sum = ctrlSum(arr, n);
    int c = 0;
    int m = 0;
    int *arrDiv = divSearch(n);
    int countDiv = arrDiv[0];
    for(int l = 1; l <= countDiv; l++)
    {
        int k = arrDiv[l]; 
        for (int i = k; i < n; i++)
        {
            int t = arrIn[i];
            int j = i - k;
            c++;
            while((j >= 0) && (t < arrIn[j]))
            {
                c++;
                arrIn[j + k] = arrIn[j];
                m++;
                j = j - k;
            }
            arrIn[j + k] = t;
            m++;
        }
    }
    if (sum == ctrlSum(arrIn, n) && lineCount(arrIn, n) == 1)
    {
        int x = c + m;
        free(arrDiv);
        return x;
    }
    else
    {
        free(arrDiv);
        return 0;
    }
}
int knutShellSort(int arr[], int n)
{
    int arrIn[n];
    for (int i = 0; i < n; i++)
    {
        arrIn[i] = arr[i];
    }
    int sum = ctrlSum(arr, n);
    int c = 0;
    int m = 0;
    int *arrDiv = knutSearch(n);
    int countDiv = arrDiv[0];
    for(int l = 1; l <= countDiv; l++)
    {
        int k = arrDiv[l]; 
        for (int i = k; i < n; i++)
        {
            int t = arrIn[i];
            int j = i - k;
            c++;
            while((j >= 0) && (t < arrIn[j]))
            {
                c++;
                arrIn[j + k] = arrIn[j];
                m++;
                j = j - k;
            }
            arrIn[j + k] = t;
            m++;
        }
    }
    if (sum == ctrlSum(arrIn, n) && lineCount(arrIn, n) == 1)
    {
        int x = c + m;
        free(arrDiv);
        return x;
    }
   else
    {
        free(arrDiv);
        return 0;
    } 
}

int insertSort(int arr[], int n)
{
    int sum = ctrlSum(arr, n);
    int arrIn[n];
    int c = 0;
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
    int *arrRand1 = masGenRand(100);
    int *arrRand2 = masGenRand(200);
    int *arrRand3 = masGenRand(300);
    int *arrRand4 = masGenRand(400);
    int *arrRand5 = masGenRand(500);
    int *k1 = knutSearch(100);
    int *k2 = knutSearch(200);
    int *k3 = knutSearch(300);
    int *k4 = knutSearch(400);
    int *k5 = knutSearch(500);
    printf("\n N | h1 … hm по формуле Д.Кнута | Insert Мф+Сф | Shell Мф+Сф\n");
    printf("100| ");
    printArrayStr(k1);
    printf("                    | %d         | %d\n", insertSort(arrRand1, 100), knutShellSort(arrRand1, 100));
    printf("200| ");
    printArrayStr(k2);
    printf("                | %d        | %d\n", insertSort(arrRand2, 200), knutShellSort(arrRand2, 200));
    printf("300| ");
    printArrayStr(k3);
    printf("                | %d        | %d\n", insertSort(arrRand3, 300), knutShellSort(arrRand3, 300));
    printf("400| ");
    printArrayStr(k4);
    printf("                | %d        | %d\n", insertSort(arrRand4, 400), knutShellSort(arrRand4, 400));
    printf("500| ");
    printArrayStr(k5);
    printf("                | %d       | %d\n", insertSort(arrRand5, 500), knutShellSort(arrRand5, 500));

    printf("\n N | h1 … hm по формуле Д.Кнута | Shell Мф+Сф | h1 … hm по другой формуле    | Shell Мф+Сф\n");
    int *d1 = divSearch(100);  
    int *d2 = divSearch(200);  
    int *d3 = divSearch(300);  
    int *d4 = divSearch(400);  
    int *d5 = divSearch(500);  
    printf("100| ");
    printArrayStr(k1);
    printf("                    | %d        | ", knutShellSort(arrRand1, 100));
    printArrayStr(d1);
    printf("               | %d\n", shellSort(arrRand1, 100));
    printf("200| ");
    printArrayStr(k2);
    printf("                | %d        | ", knutShellSort(arrRand2, 200));
    printArrayStr(d2);
    printf("            | %d\n", shellSort(arrRand2, 200));
    printf("300| ");
    printArrayStr(k3);
    printf("                | %d        | ", knutShellSort(arrRand3, 300));
    printArrayStr(d3);
    printf(" | %d\n", shellSort(arrRand3, 300));
    printf("400| ");
    printArrayStr(k4);
    printf("                | %d       | ", knutShellSort(arrRand4, 400));
    printArrayStr(d4);
    printf("    | %d\n", shellSort(arrRand4, 400));
    printf("500| ");
    printArrayStr(k5);
    printf("                | %d       | ", knutShellSort(arrRand5, 500));
    printArrayStr(d5);
    printf("           | %d\n", shellSort(arrRand5, 500));
    free(arrRand1); free(arrRand2); free(arrRand3); free(arrRand4); free(arrRand5);
    free(k1); free(k2); free(k3); free(k4); free(k5);
    free(d1); free(d2); free(d3); free(d4); free(d5);
}