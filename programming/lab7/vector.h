#ifndef VECTOR_H
#define VECTOR_H
#include <stddef.h>
struct Vector
{
    int* data;       // Указатель на массив данных
    size_t size;     // Текущий размер (количество элементов)
    size_t capacity; // Вместимость (выделенная память)
};
struct Vector *vectorCreate();
void vectorClean(struct Vector *vec);
int vectorAppend(struct Vector *vec, int value);
int vectorDelete(struct Vector *vec, size_t index);
int binSearch(const int* arr, int left, int right, int target);
void selectSort(int* arr, int n);

#endif // ADDS_H