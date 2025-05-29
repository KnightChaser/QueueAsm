#include <stdio.h>
#include <stdlib.h>

typedef struct Queue Queue;
extern Queue *queue_create(void);

int main(int argc, char *argv[]) {
    Queue *q = queue_create();
    if (!q) {
        fprintf(stderr, "Failed to create queue\n");
        return EXIT_FAILURE;
    }
    printf("Queue allocated at: %p\n", (void *)q);

    return 0;
}
