#include "min_heap.h"

void swap(Array array, size_t index_1, size_t index_2) {
    Node temp = array->data[index_1];
    array->data[index_1] = array->data[index_2];
    array->data[index_2] = temp;
}

void heapify(Array array, size_t index, bool (*less_than)(Node a, Node b)) {
    size_t smallest = index;

    if (
      2 * index + 1 < array->used && 
      (*less_than)(array->data[2 * index + 1], array->data[index])) 
    {
        smallest = 2 * index + 1;
    }

    if (
      2 * index + 2 < array->used && 
      (*less_than)(array->data[2 * index + 2], array->data[index])) 
    {
        smallest = 2 * index + 2;
    }

    if (smallest != index) {
        swap(array, index, smallest);
        heapify(array, smallest, less_than);
    }
}

void putHeap(Array array, Node item, bool (*less_than)(Node a, Node b)) {
    appendArray(array, item);

    for (size_t index = array->used - 1; index > 0; index = (index - 1) / 2) {
        heapify(array, index, less_than);
    }

    heapify(array, 0, less_than);
}

Node popHeap(Array array, bool (*less_than)(Node a, Node b)) {
    size_t index = 0;

    size_t reversed = array->used; // Reverse bits of num, adding a 1 to most sig digit, 
    size_t path = 1;
    while (reversed > 1) {
        path <<= 1;
        path |= (reversed & 1);
        reversed >>= 1;
    }
    
    while (path > 1) {
        char dir = path & 1;
        if (dir == 0) {
            swap(array, index, 2 * index + 1);
            index = 2 * index + 1;
        }
        else if (dir == 1) {
            swap(array, index, 2 * index + 2);
            index = 2 * index + 2;
        }
        path >>= 1;
    }

    Node temp = popArray(array);
    heapify(array, 0, less_than);

    return temp;
}