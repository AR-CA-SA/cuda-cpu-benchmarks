#include <stdio.h>

typedef struct{
    int *array;
    size_t elements;
    size_t capacity;
}array;

typedef enum{
    VEC_OK = 0,
    VEC_ZERO_CAPACITY,
    VEC_ERR_NULL,
    VEC_DIFF_DIM,
    VEC_DIFF_ELEMENTS,
}vector_status;

void initVector(array *vector, size_t initCapacity);

void insertElement(array *vector, int element);

void deleteVector(array *vector);