#include <stdio.h>
#include <stdlib.h>
#include "func.h"

struct phones {
    char *sub;
    long long number;  // используем long long для больших номеров телефонов
    char *adr;
    int post;
};

struct phones *sortPhones(struct phones arr[], int n) {
    struct phones *arrIn = malloc(n * sizeof(struct phones));
    if (arrIn == NULL) {
        printf("Ошибка выделения памяти!\n");
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        arrIn[i] = arr[i];
    }

    for (int i = 1; i < n; i++) {
        struct phones temp = arrIn[i];  
        int j = i - 1;

        while (j >= 0 && (
            arrIn[j].post > temp.post ||
            (arrIn[j].post == temp.post && arrIn[j].number > temp.number)
        )) {
            arrIn[j + 1] = arrIn[j];
            j--;
        }
        arrIn[j + 1] = temp;
    }

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

    struct phones *arrSort = sortPhones(arr, 7);
    if (arrSort == NULL) {
        return 1;  // ошибка выделения памяти
    }

    printf("subscriber | phone number | address | post number\n");
    for (int i = 0; i < 7; i++) {
        printf("%s | %lld | %s | %d\n",
               arrSort[i].sub, arrSort[i].number, arrSort[i].adr, arrSort[i].post);
    }

    free(arrSort);  
    return 0;
}
