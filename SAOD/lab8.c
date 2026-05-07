#include <stdio.h>
#include <stdlib.h>
#include "func.h"

struct phones {
    char *sub;
    long long number;  // используем long long для больших номеров телефонов
    char *adr;
    int post;
};
int *sortOnNum(struct phones arr[], int n)
{
   int *arrIn = malloc(n * sizeof(int));
   for(int i = 0; i < n; i++)
   {
    arrIn[i] = i;
   } 
   int l = 0;
    int r = n - 1;
    int k = n;
    do
    {
        for(int i = r; i > l; i--)
        {
            if (arr[arrIn[i]].number < arr[arrIn[i - 1]].number)
            {
                int temp = arrIn[i];
                arrIn[i] = arrIn[i - 1];
                arrIn[i - 1] = temp;
                k = i;
            }  
        }
        l = k;
        for(int j = l; j < r; j++)
        {
            if (arr[arrIn[j]].number > arr[arrIn[j + 1]].number)
            {
                int temp = arrIn[j];
                arrIn[j] = arrIn[j + 1];
                arrIn[j + 1] = temp;
                k = j;
            }   
        }
        r = k;
    } while (l < r);
    
        return arrIn;
}
int *sortOnPost(struct phones arr[], int n)
{
    int *arrIn = malloc(n * sizeof(int));
   for(int i = 0; i < n; i++)
   {
    arrIn[i] = i;
   } 
   int l = 0;
    int r = n - 1;
    int k = n;
    do
    {
        for(int i = r; i > l; i--)
        {
            if (arr[arrIn[i]].post < arr[arrIn[i - 1]].post)
            {
                int temp = arrIn[i];
                arrIn[i] = arrIn[i - 1];
                arrIn[i - 1] = temp;
                k = i;
            }  
        }
        l = k;
        for(int j = l; j < r; j++)
        {
            if (arr[arrIn[j]].post > arr[arrIn[j + 1]].post)
            {
                int temp = arrIn[j];
                arrIn[j] = arrIn[j + 1];
                arrIn[j + 1] = temp;
                k = j;
            }   
        }
        r = k;
    } while (l < r);
    
        return arrIn;
}

int main() {
    struct phones arr[7];

    arr[0].sub  = "Ivan Sidorov";
    arr[0].number = 83835550101LL;
    arr[0].post = 630301;
    arr[0].adr = "Kr. Prosp 1";

    arr[1].sub  = "Petr Ivanov";
    arr[1].number = 83835550252LL;
    arr[1].post = 630821;
    arr[1].adr = "Kr. Prosp 78";

    arr[2].sub  = "Maria Petrovna";
    arr[2].number = 83835557313LL;
    arr[2].post = 630431;
    arr[2].adr = "Lenina 15";

    arr[3].sub  = "Alexei Smirnov";
    arr[3].number = 83831550404LL;
    arr[3].post = 639021;
    arr[3].adr = "Gagarina 22";

    arr[4].sub  = "Elena Kovaleva";
    arr[4].number = 83835550508LL;
    arr[4].post = 630041;
    arr[4].adr = "Tsvetochnaya 7";

    arr[5].sub  = "Dmitry Orlov";
    arr[5].number = 83835550505LL;
    arr[5].post = 630041;
    arr[5].adr = "Sovetskaya 45";

    arr[6].sub  = "Olga Vasilieva";
    arr[6].number = 83835550503LL;
    arr[6].post = 630041;
    arr[6].adr = "Mira 101";

    int *indNum = sortOnNum(arr, 7); 
    int *indPost = sortOnPost(arr, 7); 
    printf("subscriber | phone number | address | post number\n");
    for (int i = 0; i < 7; i++) {
        printf("%s | %lld | %s | %d\n",
               arr[indNum[i]].sub, arr[indNum[i]].number, arr[indNum[i]].adr, arr[indNum[i]].post);
    }
    printf("\nsubscriber | phone number | address | post number\n");
    for (int i = 0; i < 7; i++) {
        printf("%s | %lld | %s | %d\n",
               arr[indPost[i]].sub, arr[indPost[i]].number, arr[indPost[i]].adr, arr[indPost[i]].post);
    }

}