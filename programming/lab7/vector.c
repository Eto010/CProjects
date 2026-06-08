#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
/* Функция: создание динамического массива */
struct Vector* vectorCreate() {
    struct Vector* vec = (struct Vector*)malloc(sizeof(struct Vector));
    if (!vec) return NULL; // Ошибка выделения памяти
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
    return vec;
}

/* Функция: очистка динамического массива (освобождение памяти) */
void vectorClean(struct Vector* vec) {
    if (vec) {
        free(vec->data); // Освободить память данных
        vec->data = NULL;
        vec->size = 0;
        vec->capacity = 0;
    }
}

/* Функция: добавление элемента в конец динамического массива */
int vectorAppend(struct Vector* vec, int value) {
    if (!vec) return 0; // Проверка на NULL

    // Увеличение вместимости, если требуется
    if (vec->size >= vec->capacity) {
        size_t newCap = vec->capacity == 0 ? 1 : vec->capacity * 2;
        int* newData = realloc(vec->data, newCap * sizeof(int));
        if (!newData) return 0; // Ошибка перераспределения
        vec->data = newData;
        vec->capacity = newCap;
    }

    vec->data[vec->size] = value;
    vec->size++;
    return 1; // Успех
}

/* Функция: удаление элемента по индексу */
int vectorDelete(struct Vector* vec, size_t index) {
    if (!vec || index >= vec->size) return 0; // Проверка валидности

    // Сдвиг элементов влево
    for (size_t i = index; i < vec->size - 1; i++) {
        vec->data[i] = vec->data[i + 1];
    }
    vec->size--;
    return 1; // Успех
}

/* Функция: бинарный поиск (возвращает индекс элемента или -1) */
int binSearch(const int* arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2; // Предотвращение переполнения
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1; // Не найден
}

/* Функция: сортировка выбором (прямая сортировка) */
void selectSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        // Обмен минимального элемента с текущим
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}
