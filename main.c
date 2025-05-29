#include <stdio.h>
#include <stdlib.h>

typedef struct Queue Queue;
extern Queue *queue_create(void);
extern void queue_enqueue(Queue *q, int value);

int main(int argc, char *argv[]) {
    Queue *q = queue_create();
    if (!q) {
        fprintf(stderr, "Failed to create queue\n");
        return EXIT_FAILURE;
    }
    printf("Queue allocated at: %p\n", (void *)q);

    queue_enqueue(q, 42);
    printf("Enqueued 42 into queue at %p\n", (void *)q);

    return EXIT_SUCCESS;
}
