#include "array.h"

void initArray(Array array) {
    array->used = 0;
    array->size = 0;
    array->data = NULL;
}

void appendArray(Array array, Node item) {
    if (!array->data) {
        array->data = calloc(8, sizeof(Node));
        array->size = 8;
    }
    else if (array->used >= array->size) {
        array->size *= 2;
        array->data = realloc(array->data, array->size * sizeof(Node));
    }

    array->data[array->used] = item;
    array->used += 1;
}

Node popArray(Array array) {
    if (!array->data) {
        printf("Error: Array is already empty. \n");
        exit(1);
    }

    array->used -= 1;
    Node temp = array->data[array->used];

    if (array->used * 2 < array->size && array->size > 8) {
        array->size /= 2;
        array->data = realloc(array->data, array->size * sizeof(Node));
    }

    return temp;
}

void freeArray(Array array) {
    array->used = 0;
    array->size = 0;

    free(array->data);
    array->data = NULL;
}

void printArray(Array array, void (*print_func)(Node item)) {
    for (size_t index = 0; index < array->used; index += 1) {
        print_func(array->data[index]);
    }
    printf("\n");
}