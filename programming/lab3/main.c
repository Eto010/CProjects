#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>

char getch_unix() {
    struct termios oldt, newt;
    char ch;

    // Получаем текущие настройки терминала
    tcgetattr(STDIN_FILENO, &oldt);

    // Копируем и изменяем настройки
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);  // Отключаем канонический режим и эхо

    // Применяем новые настройки
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Считываем один символ
    ch = getchar();

    // Восстанавливаем старые настройки
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);


    return ch;
}

struct Rooms{
    char name[50];
    int level;
    int number;
    int resolution;
    struct Rooms *next;
    struct Rooms *prev;
};

void append(struct Rooms *r, const char* name, int level, int number, int resolution) {
    while (r->next != NULL) {
        r = r->next;
    }

    struct Rooms *rnew = malloc(sizeof(struct Rooms));
    if (rnew == NULL) {
        printf("Ошибка выделения памяти\n");
        return;
    }

    strcpy(rnew->name, name);
    rnew->level = level;
    rnew->number = number;
    rnew->resolution = resolution;
    rnew->prev = r;
    rnew->next = NULL;

    r->next = rnew; // Связываем старый последний элемент с новым
}


struct Rooms* prepend(struct Rooms *r, const char* name, int level, int number, int resolution) {
    struct Rooms *rnew = malloc(sizeof(struct Rooms));
    if (rnew == NULL) {
        printf("Ошибка выделения памяти\n");
        return r; // Возвращаем старый головной элемент
    }

    strcpy(rnew->name, name);
    rnew->level = level;
    rnew->number = number;
    rnew->resolution = resolution;
    rnew->prev = NULL;
    rnew->next = r;

    if (r != NULL) {
        r->prev = rnew;
    }

    return rnew; // Возвращаем новый головной элемент
}


// Очистка списка
void clear(struct Rooms *head) {
    if (head->prev != NULL)
    {
        while (head->prev != NULL) {
        head = head->prev;
        }
    }
    while(head->next != NULL)
    {
        struct Rooms* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        (temp->prev)->next = NULL;
        free(temp);
    }
    printf("Память очищена успешно");
}



void printList(struct Rooms *r) {
    // Идём к первому элементу списка
    while (r->prev != NULL) {
        r = r->prev;
    }

    while (r != NULL) {
        printf("[Имя: %s | Уровень: %d | Номер: %d | Размер: %d] \n", r->name, r->level, r->number, r->resolution);
        r = r->next;
    }
    printf("\n");
}


int randInt(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main() {
    srand(time(NULL)); // Инициализация генератора случайных чисел

    const char *names[] = {"Пещера", "Склад", "Башня", "Дом", "Лес", "Тренировочная площадка", "Площадь", "Болото", "Пустыня", "Равнина"};
    int x;
    scanf("%d", &x);

    struct Rooms first;
    first.level = randInt(1, 6);
    strcpy(first.name, names[randInt(0, 9)]); // 0..9, чтобы не выйти за границы
    first.number = 1;
    first.resolution = randInt(10, 100);
    first.prev = NULL; // Инициализируем указатели
    first.next = NULL;

    for (int i = 0; i < x; i++) {
        append(&first, names[randInt(0, 9)], randInt(1, 6), x + 2, randInt(10, 100));
    }
    char but;
    struct Rooms cur = first;
    while((but != 'q') || (but != 'Q'))
    {
        but = getch_unix();
        if((but == 'q' ) || but == 'Q')
        {
            break;
        }
        if ((but == 'w') || (but == 'W'))
        {
            while (cur.next != NULL) 
            {
                cur = *cur.next;
            }
            printf("[Имя: %s | Уровень: %d | Номер: %d | Размер: %d] \n", cur.name, cur.level, cur.number, cur.resolution);
        } 
        else if ((but == 's') || (but == 'S'))
        {
            while (cur.prev != NULL) 
            {
                cur = *cur.prev;
            }
            printf("[Имя: %s | Уровень: %d | Номер: %d | Размер: %d] \n", cur.name, cur.level, cur.number, cur.resolution);
        } 
        else if ((but == 'a') || (but == 'A'))
        {
            if (cur.prev != NULL)
            {
            cur = *cur.prev;
            printf("[Имя: %s | Уровень: %d | Номер: %d | Размер: %d] \n", cur.name, cur.level, cur.number, cur.resolution);
            }
            else
            {
                printf("[Это и так первый элемент]\n");
            }
        } 
        else if ((but == 'd') || (but == 'D'))
        {
            if (cur.next != NULL)
            {
            cur = *cur.next; 
            printf("[Имя: %s | Уровень: %d | Номер: %d | Размер: %d] \n", cur.name, cur.level, cur.number, cur.resolution);
            }
            else
            {
                printf("[Это и так последний элемент]\n");
            }
        } 
        else if ((but == 'e') || (but == 'E'))
        {
            printList(&cur);
        } 
    }
    clear(&first); // Освобождаем память
    return 0;
}
