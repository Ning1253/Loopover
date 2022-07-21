#include "moves.h"

void R(Node* a, int n) {
    char temp = a->board[N * (n + 1) - 1];
    for (int i = N * (n + 1) - 1; i > N * n; i--) {
        a->board[i] = a->board[i - 1];
    }
    a->board[N * n] = temp;

    appendMoveArray(a->moves, (char [2]){0, n});
}

void L(Node* a, int n) {
    char temp = a->board[N * n];
    for (int i = N * n; i < N * (n + 1) - 1; i++) {
        a->board[i] = a->board[i + 1];
    }
    a->board[N * (n + 1) - 1] = temp;

    appendMoveArray(a->moves, (char [2]){3, n});
}

void D(Node* a, int n) {
    char temp = a->board[N * (N - 1) + n];
    for (int i = N; i > 0; i--) {
        a->board[N * (i - 1) + n] = a->board[N * (i - 2) + n];
    }
    a->board[n] = temp;

    appendMoveArray(a->moves, (char [2]){1, n});
}

void U(Node* a, int n) {
    char temp = a->board[n];
    for (int i = 0; i < N - 1; i++) {
        a->board[N * i + n] = a->board[N * (i + 1) + n];
    }
    a->board[N * (N - 1) + n] = temp;

    appendMoveArray(a->moves, (char [2]){2, n});
}