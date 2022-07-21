#ifndef c_node_h
#define c_node_h

#include <math.h>
#include <stdbool.h>

#include "move_array.h"


#define min(a, b) (a <= b ? a : b)
#define N 4


typedef struct node_type {
    int h;
    char board[N * N];
    MoveArray moves;
} Node;


bool less(Node a, Node b);
bool solved(Node a);
int h(Node node);

void printNode(Node node);
Node copyNode(Node node);

#endif