#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "func.h"

int main()
{
    struct list *stackR = stackGenRand(10); printList(stackR); printf("%d, %d \n", listCtrlSum(stackR), stackLineCount(stackR)); clearList(stackR);
    struct list *stackH = stackGenHigh(10); printList(stackH); printf("%d, %d \n", listCtrlSum(stackH), stackLineCount(stackH)); clearList(stackH);
    struct list *stackL = stackGenLow(10); printList(stackL); printf("%d, %d \n", listCtrlSum(stackL), stackLineCount(stackR)); clearList(stackL);
    struct list *queueR = queueGenRand(10); printList(queueR); printf("%d, %d \n", listCtrlSum(queueR), queueLineCount(queueR));clearList(queueR);
    struct list *queueH = queueGenHigh(10); printList(queueH); printf("%d, %d \n", listCtrlSum(queueH), queueLineCount(queueH)); clearList(queueH);
    struct list *queueL = queueGenLow(10); printList(queueL); printf("%d, %d \n", listCtrlSum(queueL), queueLineCount(queueL)); 
    doublePrintList(queueL); clearList(queueL);
}