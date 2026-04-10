#include <stdio.h>
#include "../include/adds.h"

int main()
{
    struct bankAccount *arr = arrBankFillRand(100);
    struct bankAccount *arrSort = insertSort(arr, 100);
    printArrBankAcc(arr, 100);
    printArrBankAcc(arrSort, 100);
}