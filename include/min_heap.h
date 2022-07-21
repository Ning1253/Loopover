#ifndef c_min_heap_h
#define c_min_heap_h

#include <stdbool.h>

#include "array.h"

void swap(Array array, size_t index_1, size_t index_2);
void heapify(Array array, size_t index, bool (*less_than)(Node a, Node b));

void putHeap(Array array, Node item, bool (*less_than)(Node a, Node b));
Node popHeap(Array array, bool (*less_than)(Node a, Node b));

#endif