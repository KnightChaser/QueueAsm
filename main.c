#include <stdio.h>
#include <stdlib.h>

typedef struct Queue Queue;
extern Queue *queue_create(void);
extern void queue_enqueue(Queue *q, int value);
extern long queue_count(Queue *q);
extern int queue_is_empty(Queue *q);

int main(int argc, char *argv[]) {
    Queue *q = queue_create();
    if (!q) {
        fprintf(stderr, "Failed to create queue\n");
        return EXIT_FAILURE;
    }
    printf("Queue allocated at: %p\n", (void *)q);

    printf("Before enqueue(42) -> Empty? %d, Count: %ld\n", queue_is_empty(q),
           queue_count(q));

    queue_enqueue(q, 42);
    printf("After enqueue(42) -> Empty? %d, Count: %ld\n", queue_is_empty(q),
           queue_count(q));

    return EXIT_SUCCESS;
}
