#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int *array;
    size_t elements;
    size_t capacity;
}array;


void initVector(array *vector, size_t initCapacity){
    vector->array = malloc(sizeof(int)*initCapacity);
    if (initCapacity == 0){
        printf("initiCapacity == %ld, value must be greater than 0\n", initCapacity);
    }
    if (vector->array == NULL){
        puts("Memory allocation failed");
        return;
    }
    vector->elements = 0;
    vector->capacity = initCapacity;
}


void insertElement(array *vector, int element){
    
    if(vector->capacity == 0){
        puts("The capacity of the vector is 0. The vector capacity must be > 0 to insert an element");
        return;
    }   
    if (vector->elements == vector->capacity){
        vector->capacity *= 2;
        vector->array = realloc(vector->array, vector->capacity*sizeof(int));
        if (vector->array == NULL){
            puts("Memory reallocation failed");
        return;

    }
    }
    vector->array[vector->elements++] = element;

} 

void deleteVector(array *vector){
    free(vector->array);
    vector->array = NULL;
    vector->elements = 0;
    vector->capacity = 0;

}
