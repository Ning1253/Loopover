#ifndef c_move_array_h
#define c_move_array_h

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct move_array_type {
    size_t used;
    size_t size;
    char (*data)[2];
}* MoveArray;

void initMoveArray(MoveArray array);
void appendMoveArray(MoveArray array, char item[2]);
void freeMoveArray(MoveArray array);

void printMoveArray(MoveArray array);

#endif