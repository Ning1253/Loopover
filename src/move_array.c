#include "move_array.h"

static char dirs[4] = "RDUL";

void initMoveArray(MoveArray array) {
    array->used = 0;
    array->size = 0;
    array->data = NULL;
}

void appendMoveArray(MoveArray array, char item[2]) {
    if (!array->data) {
        array->data = calloc(8, sizeof(char[2]));
        array->size = 8;
    }
    else if (array->used >= array->size) {
        array->size *= 2;
        array->data = realloc(array->data, array->size * sizeof(char[2]));
    }

    array->data[array->used][0] = item[0];
    array->data[array->used][1] = item[1];

    array->used += 1;
}

void freeMoveArray(MoveArray array) {
    array->used = 0;
    array->size = 0;

    free(array->data);
    array->data = NULL;
}

void printMoveArray(MoveArray array) {
    if (array == NULL) return;
    
    for (size_t index = 0; index < array->used; index += 1) {
        printf("%c%d", dirs[(int)array->data[index][0]], array->data[index][1]);
        if (index < array->used - 1) printf(", ");
    }
    printf("\n");
}