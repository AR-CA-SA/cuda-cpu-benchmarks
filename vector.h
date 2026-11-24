#include <stdio.h>
#include "vector.c"
typedef struct{
    int *array;
    size_t elements;
    size_t capacity;
}array;

void initVector(array *vector, size_t initCapacity);

void insertElement(array *vector, int element);

void deleteVector(array *vector);