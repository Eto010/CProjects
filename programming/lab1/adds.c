#include <stdio.h>
#include <stdlib.h>
#include "adds.h"

struct bankAccount
{
    unsigned int num;
    unsigned int type;
    unsigned int balance;
    unsigned int deadline;
};

int genRand(int a, int b)
{
    int x;
    x = a + rand() % b;
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
        arrIn[i].deadline = genRand(2025, 2050);
    }
    return arrIn;
}