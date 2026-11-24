#include <stdio.h>
#include "vector.c"

typedef enum{
    DIFF_DIMENSION, DIFF_ELEMENTS, EMPTY_VECTOR
}dot;

static void error_condition(dot error_type, array *a, array *b){
    if (error_type == DIFF_DIMENSION){
        printf("Mismatch dimensions between a : (%ld) and b : (%ld)\n", a->capacity,b->capacity);
    }else if(error_type == DIFF_ELEMENTS){
        printf("Mismatch number of elements a : (%ld) and b : (%ld)\n", a->elements,b->elements);
    }else if(error_type == EMPTY_VECTOR){
        if (a->capacity == 0){
            puts("Vector a is empty");
        }
        if (b->capacity == 0){
            puts("Vector b is empty");
        }
    }
}

int dot_product(array *a, array *b){
    if (a->capacity != b->capacity){
        error_condition(DIFF_DIMENSION, a,b);
        return 0;
    }else if(a->elements != b->elements){
        error_condition(DIFF_ELEMENTS, a,b);
        return 0;
    }else if (a->capacity == 0 || b->capacity == 0){
        error_condition(EMPTY_VECTOR,a,b);
        return 0;
    }
    size_t nElements = a->elements;
    int result = 0;
    for (size_t i = 0 ; i < nElements; i++){
        result += a->array[i]*b->array[i];
    }
    return result;
}




