#include <stdio.h>

struct Book{ // Структура, в которую будет парситься запись из БД
    char aut[12];
    char tit[32];
    char pub[16];
    int year;
    int cop;
};

void printBook(struct Book data) // Вывод данных о книге
{
    printf("Author: %.*s\nTitle: %.*s\nPublisher: %.*s\nYear of publication: %d\nCount of pages: %d\n", 12, data.aut, 32, data.tit, 16, data.pub, data.year, data.cop);
}

struct List{ // Структура списка, в который будет записываться БД
    struct Book data;
    struct List * next;
};

void printList(const struct List *head) { // Итеративно выводим список
    while (head != NULL) {
        printBook(head->data);
        head = head->next;
    }
}