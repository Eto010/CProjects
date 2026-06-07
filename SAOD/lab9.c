#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "func.h"

int buildHeap(int *arr, int l, int r, int *cOut, int*mOut)
{
    int c = 0;
    int m = 0;
    int x = arr[l];
    int i = l;
    while(1)
    {
        int j = 2 * i + 1;
        if (j > r)
        {
            break;
        }
        c++;
        (*cOut)++;
        if ((j < r) && (arr[j + 1] <= arr[j]))
        {
            j++;
        }
        c++;
        (*cOut)++;
        if (x <= arr[j])
        {
            break;
        }
        arr[i] = arr[j];
        m++;
        (*mOut)++;
        i = j;
    }
    arr[i] =  x;
    m++;
    (*mOut)++;
    return c + m;
}

int heapSort(int *arr, int n)
{
    int c = 0;
    int m = 0;
    int l = n / 2;
    while(l > 0)
    {
        buildHeap(arr, l, n, &c, &m);
        l--;
    }
    int r = n ;
    while(r > 0)
    {
        int temp = arr[0];
        m++; m++;
        arr[0] = arr[r - 1];
        arr[r - 1] = temp;
        r = r - 1;
        buildHeap(arr, 0, r - 1, &c, &m); 
    }
    return c + m;
}
// Теоретическая оценка для построения пирамиды
double theoreticalBuildHeap(int n) {
    double mt, ct;
    mt = log2(n) + 2;
    ct = 2 * log(n);
    return ct + mt; // M ≈ 2n, C ≈ 2n
}


int main() {

    int sizes[] = {100, 200, 300, 400, 500};
    int numSizes = 5;

    printf("Таблица 1: Трудоёмкость построения пирамиды\n");
    printf("N\tM+C теоретич.\tУбыв. \tСлуч. \t Возр.\n");
    printf("---\t-----------\t----\t----\t----\n");

    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];
        double theoretical = theoreticalBuildHeap(n);
        int c, m;
        c = 0; m = 0;
        // Убывающий массив
        int* arr1 = masGenLow(n);
        int result1 = buildHeap(arr1, 0, n, &c, &m);
        free(arr1);

        // Случайный массив
        int* arr2 = masGenRand(n);
        int result2 = buildHeap(arr2, 0, n, &c, &m);
        free(arr2);

        // Возрастающий массив
        int* arr3 = masGenHigh(n);
        int result3 = buildHeap(arr3, 0, n, &c, &m);
        free(arr3);


        printf("%d\t%0.f\t\t%d\t%d\t%d\n", n, theoretical, result1, result2, result3);
    }

    printf("\nТаблица 2: Трудоёмкость пирамидальной сортировки\n");
    printf("N\tУбыв.   Возр.   Случ.\n");
    printf("---\t----\t----\t----\n");

    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];

        // Убывающий массив
        int* arr1 = masGenLow(n);
        int result1 = heapSort(arr1, n);
        free(arr1);

        // Возрастающий массив
        int* arr2 = masGenHigh(n);
        int result2 = heapSort(arr2, n);
        free(arr2);

        // Случайный массив
        int* arr3 = masGenRand(n);
        int result3 = heapSort(arr3, n);
        free(arr3);
    

        printf("%d\t%d\t%d\t%d\n",
               n, result1, result2, result3);
    }

    return 0;
}
