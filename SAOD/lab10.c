#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "func.h"

int hoarSort(int *arr, int l, int r, int *c, int *m) {
    // Базовый случай рекурсии
    if (l >= r) {
        return *c + *m;
    }

    int x = arr[l];  // Опорный элемент
    int i = l, j = r;

    while (i <= j) {
        // Поиск элемента слева, который >= опорному
        while (arr[i] < x) {
            i++;
            (*c)++;
        }

        // Поиск элемента справа, который <= опорному
        while (arr[j] > x) {
            j--;
            (*c)++;
        }

        if (i <= j) {
            // Обмен элементов, если они не совпадают
            if (i != j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                (*m) += 3;  // 3 перемещения: temp, arr[i], arr[j]
            }
            i++;
            j--;
        }
    }

    // Рекурсивная сортировка левой и правой частей
    hoarSort(arr, l, j, c, m);
    hoarSort(arr, i, r, c, m);

    return *c + *m;
}

int hoarSort2(int *arr, int l, int r, int *c) {
    (*c)++;
    if (l >= r) {
        return *c;
    }
    int x = arr[l];  // Опорный элемент
    int i = l, j = r;

    while (i <= j) {
        // Поиск элемента слева, который >= опорному
        while (arr[i] < x) {
            i++;
        }

        // Поиск элемента справа, который <= опорному
        while (arr[j] > x) {
            j--;
            
        }

        if (i <= j) {
            // Обмен элементов, если они не совпадают
            if (i != j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            i++;
            j--;
        }
    }

    // Рекурсивная сортировка левой и правой частей
    (*c)++;
    hoarSort2(arr, l, j, c);
    hoarSort2(arr, i, r, c);

    return *c;
}

int quickSort(int *arr, int l, int r, int *c)
{
    (*c)++;
        // Базовый случай: если диапазон пуст или содержит один элемент
    if (l >= r) {
        return *c;
    }

    int x = arr[l];  // Опорный элемент (первый элемент диапазона)
    int i = l, j = r;

    // Разбиение массива на две части
    while (i <= j) {
        // Поиск элемента слева, который >= опорному
        while (arr[i] < x) {
            i++;        }

        // Поиск элемента справа, который <= опорному
        while (arr[j] > x) {
            j--;        }

        if (i <= j) {
            // Обмен элементов, если они не совпадают
            if (i != j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            i++;
            j--;
        }
    }

    // Рекурсивная сортировка левой и правой частей
    // Сортируем левую часть: от l до j
    if (l < j) {
        quickSort(arr, l, j, c);
    }
    // Сортируем правую часть: от i до r
    else {
        quickSort(arr, i, r, c);
    }

    return *c;
}

int main() {
    int sizes[5] = {100, 200, 300, 400, 500};
    int numSizes = 5;

    printf("1. Трудоемкость метода Хоара\n");
    printf("N\tQuiksort(Mф + Сф)\n");
    printf("\tУбыв. Возр. Случ.\n");
    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];

        // Убывающий массив
        int cl = 0, ml = 0;
        int *low = masGenLow(n);
        hoarSort(low, 0, n - 1, &cl, &ml);
        int resultLow = cl + ml;
        free(low);

        // Возрастающий массив
        int ch = 0, mh = 0;
        int *high = masGenHigh(n);
        hoarSort(high, 0, n - 1, &ch, &mh);
        int resultHigh = ch + mh;
        free(high);

        // Случайный массив
        int cr = 0, mr = 0;
        int *rand = masGenRand(n);
        hoarSort(rand, 0, n - 1, &cr, &mr);
        int resultRand = cr + mr;
        free(rand);

        printf("%d\t%d\t%d\t%d\n", n, resultLow, resultHigh, resultRand);
    }
    printf("2. Сравнение двух вариантов быстрой сортировки\n");
    printf("N\tQuicksort1\t Quicksort2\n");
    printf("\tУбыв. Случ. Возр.\t Убыв. Случ. Возр.\n");
    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];

        // Убывающий массив
        int clH = 0;
        int *lowH = masGenLow(n);
        hoarSort2(lowH, 0, n - 1, &clH);
        int resultLowH = clH;
        free(lowH);
        int clQ = 0;
        int *lowQ = masGenLow(n);
        quickSort(lowQ, 0, n - 1, &clQ);
        int resultLowQ = clQ;
        free(lowQ);

        // Возрастающий массив
        int chH = 0;
        int *highH = masGenHigh(n);
        hoarSort2(highH, 0, n - 1, &chH);
        int resultHighH = chH;
        free(highH);
        int chQ = 0;
        int *highQ = masGenHigh(n);
        quickSort(highQ, 0, n - 1, &chQ);
        int resultHighQ = chQ;
        free(highQ);

        // Случайный массив
        int crH = 0;
        int *randH = masGenRand(n);
        hoarSort2(randH, 0, n - 1, &crH);
        int resultRandH = crH;
        free(randH);
        int crQ = 0;
        int *randQ = masGenRand(n);
        quickSort(randQ, 0, n - 1, &crH);
        int resultRandQ = crH;
        free(randQ);

        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", n, resultLowH, resultRandH, resultHighH, resultLowQ, resultRandQ, resultHighQ);
    }
    return 0;
}
