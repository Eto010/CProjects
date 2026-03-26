//Binary Search
#include <stdio.h>
#include <stdlib.h> 
#include "func.h"

int binarySearch1(int arr[], int n, int x)
{
    int c = 0;
    int l = 0; int r = n - 1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        c++;
        if (arr[m] == x){
            return c;
        }
        c++;
        if (arr[m] < x)
        {
            l = m + 1;
        }
        else 
        {
            r = m -1;
        }
    }
    return -1; 
}

int binarySearch2(int arr[], int n, int x)
{
    int c = 0;
    int l = 0; int r = n - 1;
    while (l < r)
    {
        int m =  (l + r) / 2;
        c++;
        if(arr[m] < x)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    c++;
    if (arr[r] == x)
    {
        return c;
    }
    else
    {
        return -1;
    }
}

int binarySearch1All(int arr[], int n, int x)
{
    int c = 0; 
    int l = 0, r = n - 1;

    while (l <= r)
    {
        int m = (l + r) / 2;
        c++;  
        if (arr[m] == x)
        {
        }
        c++; 
        if (arr[m] < x)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return c;  
}

int binarySearch2All(int arr[], int n, int x)
{
    int c = 0;
    int l = 0, r = n - 1;
    while (l < r)
    {
        int m = (l + r) / 2;
        c++;  

        if (arr[m] < x)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    c++;  
    return c;
}

int main()
{
    int *arr1 = masGenHigh(100);
    int *arr2 = masGenHigh(200);
    int *arr3 = masGenHigh(300);
    int *arr4 = masGenHigh(400);
    int *arr5 = masGenHigh(500);
    int *arr6 = masGenHigh(600);
    int *arr7 = masGenHigh(700);
    int *arr8 = masGenHigh(800);
    int *arr9 = masGenHigh(900);
    int *arr10 = masGenHigh(1000);
    printf("Введите искомое число менее 100\n");
    int d;
    scanf("%d", &d);
    printf(" N  | Сф I версия | Сф II версия\n");
    printf("100 | %d           | %d\n", binarySearch1(arr1, 100, d), binarySearch2(arr1, 100, d));
    printf("200 | %d           | %d\n", binarySearch1(arr2, 200, d), binarySearch2(arr2, 200, d));
    printf("300 | %d          | %d\n", binarySearch1(arr3, 300, d), binarySearch2(arr3, 300, d));
    printf("400 | %d          | %d\n", binarySearch1(arr4, 400, d), binarySearch2(arr4, 400, d));
    printf("500 | %d          | %d\n", binarySearch1(arr5, 500, d), binarySearch2(arr5, 500, d));
    printf("600 | %d          | %d\n", binarySearch1(arr6, 600, d), binarySearch2(arr6, 600, d));
    printf("700 | %d          | %d\n", binarySearch1(arr7, 700, d), binarySearch2(arr7, 700, d));
    printf("800 | %d          | %d\n", binarySearch1(arr8, 800, d), binarySearch2(arr8, 800, d));
    printf("900 | %d          | %d\n", binarySearch1(arr9, 900, d), binarySearch2(arr9, 900, d));
    printf("1000| %d          | %d\n", binarySearch1(arr10, 1000, d), binarySearch2(arr10, 1000, d));
    free(arr1); free(arr2); free(arr3); free(arr4); free(arr5); 
    free(arr6); free(arr7); free(arr8); free(arr9); free(arr10); 
    arr1 = masGenRandSort(100);
    arr2 = masGenRandSort(200);
    arr3 = masGenRandSort(300);
    arr4 = masGenRandSort(400);
    arr5 = masGenRandSort(500);
    arr6 = masGenRandSort(600);
    arr7 = masGenRandSort(700);
    arr8 = masGenRandSort(800);
    arr9 = masGenRandSort(900);
    arr10 = masGenRandSort(1000);
    printf("\n");
    printf(" N  | Сф All I версия | Сф All II версия\n");
    printf("100 | %d           | %d\n", binarySearch1All(arr1, 100, d), binarySearch2All(arr1, 100, d));
    printf("200 | %d           | %d\n", binarySearch1All(arr2, 200, d), binarySearch2All(arr2, 200, d));
    printf("300 | %d          | %d\n", binarySearch1All(arr3, 300, d), binarySearch2All(arr3, 300, d));
    printf("400 | %d          | %d\n", binarySearch1All(arr4, 400, d), binarySearch2All(arr4, 400, d));
    printf("500 | %d          | %d\n", binarySearch1All(arr5, 500, d), binarySearch2All(arr5, 500, d));
    printf("600 | %d          | %d\n", binarySearch1All(arr6, 600, d), binarySearch2All(arr6, 600, d));
    printf("700 | %d          | %d\n", binarySearch1All(arr7, 700, d), binarySearch2All(arr7, 700, d));
    printf("800 | %d          | %d\n", binarySearch1All(arr8, 800, d), binarySearch2All(arr8, 800, d));
    printf("900 | %d          | %d\n", binarySearch1All(arr9, 900, d), binarySearch2All(arr9, 900, d));
    printf("1000| %d          | %d\n", binarySearch1All(arr10, 1000, d), binarySearch2All(arr10, 1000, d));
}