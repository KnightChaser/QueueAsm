#include <stdio.h>
#include <stdlib.h>

typedef struct Queue Queue;
extern Queue *queue_create(void);
extern int64_t queue_dequeue(Queue *q);
extern void queue_enqueue(Queue *q, int value);
extern long queue_count(Queue *q);
extern int queue_is_empty(Queue *q);
extern int64_t queue_peek(Queue *q);
extern void queue_print(Queue *q);

int main(int argc, char *argv[]) {
    Queue *q = queue_create();
    if (!q) {
        fprintf(stderr, "Failed to create queue\n");
        return EXIT_FAILURE;
    }
    printf("Queue allocated at: %p\n", (void *)q);

    printf("Empty? %d, Count: %ld\n", queue_is_empty(q), queue_count(q));

    queue_enqueue(q, 42);
    queue_enqueue(q, 99);
    queue_enqueue(q, 123);
    queue_enqueue(q, 256);
    queue_enqueue(q, 512);
    queue_print(q);
    printf("After enqueue 42 and 99 -> Empty? %d, Count: %ld\n",
           queue_is_empty(q), queue_count(q));

    int64_t peeked = queue_peek(q);

    printf("Peeked value: %ld -> Empty? %d, Count: %ld\n", peeked,
           queue_is_empty(q), queue_count(q));

    int64_t a = queue_dequeue(q);
    printf("Dequeued %ld -> Empty? %d, Count: %ld\n", a, queue_is_empty(q),
           queue_count(q));

    int64_t b = queue_dequeue(q);
    printf("Dequeued %ld -> Empty? %d, Count: %ld\n", b, queue_is_empty(q),
           queue_count(q));
    return EXIT_SUCCESS;
}
