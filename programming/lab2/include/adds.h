#ifndef ADDS_H
#define ADDS_H

struct bankAccount
{
    unsigned int num;
    unsigned int type;
    unsigned int balance;
    unsigned int deadline;
};
int genRand(int a, int b);
struct bankAccount *arrBankFillRand(int n);
void printArrBankAcc(struct bankAccount[], int len);
struct bankAccount *insertSort(struct bankAccount arr[], int n);

#endif // ADDS_H