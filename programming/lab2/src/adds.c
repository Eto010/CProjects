#include <stdio.h>
#include <stdlib.h>
#include "../include/adds.h"

int genRand(int a, int b)
{
    int x;
    x = a + (rand() % b);
}

struct bankAccount *arrBankFillRand(int n)
{
    struct bankAccount *arrIn = malloc(n * sizeof *arrIn);
    if (!arrIn) return NULL;
    for(int i; i < n; i++)
    {
        arrIn[i].num = 907000000 + genRand(1, 99999);
        arrIn[i].balance = genRand(10, 100000);
        arrIn[i].type = genRand(1, 7);
        arrIn[i].deadline = genRand(2025, 25);
    }
    return arrIn;
}

void printArrBankAcc(struct bankAccount arr[], int len)
{
    printf("Number | ID | Balance | Type | Deadline\n");
    for (int i = 1; i < len + 1; i++)
    {
        printf("%d | %d | %d | %d | %d\n", i, arr[i].num, arr[i].balance, arr[i].type, arr[i].deadline);
    }
}

struct bankAccount *insertSort(struct bankAccount arr[], int n)
{
    struct bankAccount *arrIn = malloc(n * sizeof *arrIn);
    if (!arrIn) return NULL;
    for(int i = 0; i < n; i++)
   {
    arrIn[i].num = arr[i].num;
    arrIn[i].type = arr[i].type;
    arrIn[i].balance = arr[i].balance;
    arrIn[i].deadline = arr[i].deadline;

   } 
    for (int i = 1; i < n; i++)
    {
        struct bankAccount t = arrIn[i];
        int j = i - 1;
        while((j > -1) && (t.balance < arrIn[j].balance))
        {
            arrIn[j + 1] = arrIn[j];
            j = j - 1;
        }
        arrIn[j + 1] = t;
    }
    return arrIn;
}