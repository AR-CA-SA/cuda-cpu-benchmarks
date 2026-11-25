#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int *array;
    size_t elements;
    size_t capacity;
}array;

typedef enum{
    VEC_OK = 0,
    VEC_ZERO_CAPACITY,
    VEC_ERR_NULL,
    VEC_ERR_ALLOC,
    VEC_DIFF_DIM,
    VEC_DIFF_ELEMENTS,
}vector_status;


vector_status initVector(array *vector, size_t initCapacity){
    if (vector == NULL) return VEC_ERR_NULL;
    if (initCapacity == 0) return VEC_ZERO_CAPACITY;
    int *temp = malloc(sizeof(int)*initCapacity);
    if (temp == NULL) return VEC_ERR_ALLOC;
    vector->elements = 0;
    vector->capacity = initCapacity;
    vector->array = temp;
}

vector_status insertElement(array *vector, int element){
    if(vector == NULL) return VEC_ERR_NULL;
    if(vector->capacity == 0) return VEC_ZERO_CAPACITY;
   
    if (vector->elements == vector->capacity){
        size_t temp_capacity = vector->capacity*2;
        int *temp = realloc(vector->array, temp_capacity*sizeof(int));
        if (temp == NULL) return VEC_ERR_NULL;
        vector->array = temp;
        vector->capacity = temp_capacity;
    }
    vector->array[vector->elements++] = element;

} 

vector_status deleteVector(array *vector){
    free(vector->array);
    vector->array = NULL;
    vector->elements = 0;
    vector->capacity = 0;

}
