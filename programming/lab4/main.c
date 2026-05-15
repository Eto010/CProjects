#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct staff {
    char name[200];
    char number[10];  // Увеличен размер для номеров до 9 цифр
    char level[20];
};

void searchID(char *namefile, int n) {
    FILE *read = fopen(namefile, "rb");
    if (read == NULL) {  // Проверка открытия файла
        printf("Ошибка открытия файла для чтения\n");
        return;
    }

    struct staff* ent = malloc(sizeof(struct staff) * n);
    if (ent == NULL) {  // Проверка выделения памяти
        printf("Ошибка выделения памяти\n");
        fclose(read);
        return;
    }

    size_t rd = fread(ent, sizeof(struct staff), n, read);
    fclose(read);  // Закрываем файл сразу после чтения

    if (rd != n) {
        printf("Предупреждение: прочитано %zu записей из %d\n", rd, n);
        n = rd;  // Корректируем количество для поиска
    }

    char search[10];
    printf("Введите ID сотрудника для поиска: ");
    scanf("%9s", search);  // Ограничение ввода до 9 символов

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(ent[i].number, search) == 0) {  // Сравнение строк
            printf("[%s | %s | %s]\n",
                   ent[i].name, ent[i].number, ent[i].level);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Такого сотрудника нет\n");
    }

    free(ent);  // Освобождение памяти
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Использование: %s <имя_файла>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }

    struct staff arr[30];
    char line[256];
    int count = 0;

    for (int i = 0; i < 30 && fgets(line, sizeof(line), file) != NULL; i++) {
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, ";");
        if (token == NULL) continue;
        strcpy(arr[i].name, token);

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        strncpy(arr[i].number, token, sizeof(arr[i].number) - 1);
        arr[i].number[sizeof(arr[i].number) - 1] = '\0';  // Гарантируем нуль-терминацию

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        strcpy(arr[i].level, token);

        count++;
    }

    fclose(file);

    FILE *db = fopen("database.dat", "wb");
    if (db == NULL) {
        printf("Ошибка создания файла базы данных\n");
        return 1;
    }

    size_t written = fwrite(arr, sizeof(struct staff), count, db);  // Пишем только заполненные записи
    fclose(db);

    if (written == count) {
        printf("Структура успешно записана в файл (%d записей)\n", count);
    } else {
        printf("Ошибка записи структуры: записано %zu из %d\n", written, count);
    }

    searchID("database.dat", count);  // Передаём реальное количество записей

    return 0;  // Успешное завершение программы
}
