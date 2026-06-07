#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "func.h"

int ctrlSum(int arr[], int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
        k += arr[i];
    return k;
}

int lineCount(int arr[], int n)
{
    int k = 0;
    for (int i = 1; i < n; i++)
        if (arr[i - 1] >= arr[i])
            k++;

    return k + 1;
}
int *masGenLow(int x)
{
    int *arrIn = malloc(x * sizeof *arrIn);
    if (!arrIn) return NULL;

    for (int i = x - 1; i >= 0; i--) {
        arrIn[i] =  x - i;
    }

    return arrIn;
}

int *masGenHigh(int x)
{
    int *arrIn = malloc(x * sizeof *arrIn);
    if (!arrIn) return NULL;

    for (int i = 0; i < x; i++) {
        arrIn[i] = i;
    }

    return arrIn;
}

int *masGenRand(int x)
{
    int *arrIn = malloc(x * sizeof *arrIn);
    if (!arrIn) return NULL;

    for (int i = 0; i < x; i++) {
        arrIn[i] = 1 + rand() % x; 
    }

    return arrIn;
}

int *divSearch(int n)
{
    float nd = (float)n; 
    float sqn = sqrtf(nd);
    int sq = (int)sqn + 1;
    int c = 0;
    for(int i = 1; i < sq; i++)
    {
        if (n % i == 0)
        {
            c++;
        }
    }
    int *arrIn = malloc((c + 1) * sizeof *arrIn);
    arrIn[0] = c;
    arrIn[c] = 1;
    c = 1;
    for(int i = sq; i > 1; i--)
    {
        if (n % i == 0)
        {
            arrIn[c] = i;
            c++;
        }
    }
    return arrIn;
}
int *knutSearch(int n)
{
    float nf = log2f((float)n);
    int log = (int)nf + 1;
    int c = 0; int hi = 0; int h = 1;
    while(hi < log)
    {
        hi = 2*h + 1;
        c++;
        h = hi;
    }
    int *arrIn = malloc((c + 1) * sizeof *arrIn);
    arrIn[0] = c;
    h = 1; hi = 0; c = 1;
    while(hi < log)
    {
        hi = 2*h + 1;
        arrIn[c] = hi;
        c++;
        h = hi;
    }
    int *arrRet = malloc((c + 2) * sizeof *arrIn);
    arrRet[0] = arrIn[0] + 1;
    arrRet[c] = 1;
    c = 1;
    for (int i = arrIn[0]; i > 0; i--)
    {
        arrRet[c] = arrIn[i];
        c++;
    }
    return arrRet;
}

void printArrayStr(int arr[])
{
    int c = arr[0];
    for(int i = 1; i <= c; i++){
        if (i != c)
        {
            printf("%d, ", arr[i]);
        }
        else
        {
            printf("%d", arr[i]);
        }
    }
}
int *masGenRandSort(int n)
{
    int *arrIn = malloc(n * sizeof *arrIn);
    if (!arrIn) return NULL;

    for (int i = 0; i < n; i++) {
        arrIn[i] = 1 + rand() % n; 
    }

    for (int i = 0; i < n - 1; i++)
    {
        int k = i;
        for (int j = i; j < n; j++)
        {
            if (arrIn[j] < arrIn[k])
            {
                k = j;
            }
        }
        int temp = arrIn[i];
        arrIn[i] = arrIn[k];
        arrIn[k] = temp;
    }
    return arrIn;
}

struct list *stackGenLow(int x) {
    if (x <= 0) return NULL;

    struct list *head = NULL;

    for (int i = x; i >= 0; i--) {
        struct list *temp = malloc(sizeof(struct list));
        if (!temp) {
            clearList(head);
            return NULL;
        }
        temp->n = i;      
        temp->a = head;  
        head = temp;      
    }
    return head;
}

struct list *stackGenHigh(int x){
    if (x <= 0) return NULL;  
    struct list *head = NULL;

    for (int i = 0; i < x; i++) {  
        struct list *temp = malloc(sizeof(struct list));
        if (!temp) {
            clearList(head); 
            return NULL;
        }
        temp->n = i;      
        temp->a = head;
        head = temp;     
    }

    return head;
}

struct list *stackGenRand(int x)
{
   struct list *list = malloc(sizeof(struct list));
    if (!list) return NULL;
    list->a = NULL;
    list->n = 0;
    for (int i = 0; i < x; i++) {
        struct list *temp  = malloc(sizeof(struct list));
        temp->a = list;
        list->n = 1 + rand() % x;
        list = temp; 
    }

    return list;
}


 struct list *queueGenLow(int x)
{
    struct list *list = malloc(sizeof(struct list));
    if (!list) return NULL;
    struct list *head = list;
    for(int i = 1; i < x; i++)
    {
        struct list *temp  = malloc(sizeof(struct list));
        list->a = temp;
        list = temp;
    }
    list->a = NULL;
    list = head;
    for (int i = x - 1; i >= 0; i--) 
    {
        list->n =  i;
        list = list->a;
    }

    return head;
}

struct list *queueGenHigh(int x)
{
    struct list *list = malloc(sizeof(struct list));
    if (!list) return NULL;
    struct list *head = list;
    for(int i = 1; i < x; i++)
    {
        struct list *temp  = malloc(sizeof(struct list));
        list->a = temp;
        list = temp;
    }
    list->a = NULL;
    list = head;
    for (int i = 0; i < x; i++) {
        list->n = i;
        list = list->a;
    }

    return head;
}

struct list *queueGenRand(int x)
{
   struct list *list = malloc(sizeof(struct list));
    if (!list) return NULL;
    struct list *head = list;
    for(int i = 1; i < x; i++)
    {
        struct list *temp  = malloc(sizeof(struct list));
        list->a = temp;
        list = temp;
    }
    list->a = NULL;
    list = head;
    for (int i = 0; i < x; i++) {
        list->n = 1 + rand() % x;
        list = list->a; 
    }

    return head;
}
int listCtrlSum (struct list *list)
{
    int n = 0;
    struct list *head = list;
    while (list->a != NULL)
    {
        n++;
        list = list->a;
    }
    int k = 0;
    list = head;
    for (int i = 0; i < n; i++){
        k += list->n;
        list = list->a;
    }
    return k;
}
int stackLineCount(struct list *list)
{
    int n = 0;
    int k = 0;
    while (list->a != NULL)
    {
        if (list->n >= (list->a)->n){
            k++;}
        list = list->a;
    }
    return k + 1;
}
int queueLineCount(struct list *list)
{
    int n = 0;
    int k = 0;
    while (list->a != NULL)
    {
        if (list->n > (list->a)->n){
            k++;}
        list = list->a;
    }
    return k + 1;
}
void clearList(struct list *head) {
    if(head->a == NULL)
    {
    free(head);
    printf("Память очищена успешно\n");
    return;
    }
    else
    {
        struct list *temp = head->a;
        free(head);
        clearList(temp);
    }

}

void printList(struct list *list) {
    while (list != NULL) {
        printf("%d ", list->n);
        list = list->a;
    }
    printf("\n");
}

void doublePrintList(struct list *list) {
    // Прямой порядок
    printf("прямой порядок; ");
    printList(list);

    // Обратный порядок
    printf("Обратный порядок: ");
    printReverseRecursive(list);
    printf("\n");
}

void printReverseRecursive(struct list *list) {
    if (list == NULL) return;
    printReverseRecursive(list->a);
    printf("%d ", list->n);
}
