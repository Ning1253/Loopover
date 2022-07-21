#include "node.h"

bool less(Node a, Node b) {
    return a.h + a.moves->used < b.h + b.moves->used;
}

bool solved(Node a) {
    for (int i = 0; i < N * N; i++) {
        if (a.board[i] != i) return false;
    }

    return true;
}

int h(Node node) {
    int total = 0;
    for (int i = 0; i < N * N; i += 1) {
        int row = abs(node.board[i] / N - i / N);
        int col = abs(node.board[i] % N - i % N);

        int dist = min(row, N - row) + min(col, N - col);
        total += dist;
    }
    
    return total;
}

void printNode(Node node) {
    printf("H: %d\n", node.h);
    printf("Board: ");
    for (int i = 0; i < N * N; i += 1) {
        printf("%d ", node.board[i]);
    }

    printf("\n\nMoves: ");

    printMoveArray(node.moves);

    printf("\n");
}

Node copyNode(Node node) {
    Node new;
    new.h = node.h;
    for (int i = 0; i < N * N; i++) new.board[i] = node.board[i];
    new.moves = malloc(sizeof(struct move_array_type));
    initMoveArray(new.moves);
    for (int i = 0; i < node.moves->used; i++) {
        appendMoveArray(new.moves, node.moves->data[i]);
    }

    return new;
}