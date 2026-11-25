#include <stdio.h>
#include "vector.h"


int dot_product(array *a, array *b){
    size_t nElements = a->elements;
    long long int result = 0;
    for (size_t i = 0 ; i < nElements; i++){
        result += a->array[i]*b->array[i];
    }
    return result;
}




