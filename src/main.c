// TODO: Change Node so that they use bits to be more space efficient. 
// TODO: Run the code but adding the stuff to a file to become a bit register. 

#include <stdio.h>

#include "min_heap.h"
#include "moves.h"

static void (*moves[4])(Node* a, int n) = {R, D, U, L};

int main(void) {
    Array q = malloc(sizeof(struct array_type));
    initArray(q);

    Node start = (Node){0, 
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 14}, malloc(sizeof(struct move_array_type))};
    
    initMoveArray(start.moves);
    start.h = h(start);

    int num = 4 * N;

    for (int m = 0; m < 4; m++) {
        for (char n = 0; n < N; n++) {
            Node copy = copyNode(start); 

            (*moves[m])(&copy, n);
            copy.h = h(copy);

            putHeap(q, copy, less);
        }
    }

    while (q->used) {
        num += 1;
        Node cur = popHeap(q, less);

        if (solved(cur)) {
            printNode(cur);
            break;
        }

        for (int m = 0; m < 4; m++) {
            for (char n = 0; n < N; n++) {
                if ((m != 3 - cur.moves->data[cur.moves->used - 1][0]) ||
                    (n != cur.moves->data[cur.moves->used - 1][1])) {
                    Node copy = copyNode(cur);

                    (*moves[m])(&copy, n);
                    copy.h = h(copy);

                    putHeap(q, copy, less);
                }
            }
        }
    }

    printf("Total Checked: %d\n", num);
}