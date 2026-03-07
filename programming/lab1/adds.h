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
bankAccount *arrBankFillRand(int n);
void printArrBankAcc(bankAccount[]);

#endif // FUNC_H