#ifndef FUNC_H
#define FUNC_H
struct list{
    int n;
    struct list *a;
};
int ctrlSum(int arr[], int n);
int lineCount(int arr[], int n);
int *masGenRand(int x);
int *masGenLow(int x);
int *masGenHigh(int x);
int *divSearch(int n);
int *knutSearch(int n);
void printArrayStr(int arr[]);
int *masGenRandSort(int n);
struct list *stackGenRand(int x);
struct list *stackGenLow(int x);
struct list *stackGenHigh(int x);
struct list *queueGenRand(int x);
struct list *queueGenLow(int x);
struct list *queueGenHigh(int x);
int listCtrlSum (struct list *list);
int stackLineCount(struct list *list);
int queueLineCount(struct list *list);
void printList(struct list *list);
void clearList(struct list *head);
void doublePrintList(struct list * list);
void printReverseRecursive(struct list *list);
#endif // FUNC_H