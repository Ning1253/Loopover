#ifndef c_array_h
#define c_array_h

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "node.h"

typedef struct array_type {
    size_t used;
    size_t size;
    Node* data;
}* Array;

void initArray(Array array);
void appendArray(Array array, Node item);
Node popArray(Array array);
void freeArray(Array array);

void printArray(Array array, void (*print_func)(Node item));


#endif