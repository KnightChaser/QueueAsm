// main.c
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue Queue;

/* Assembly‐implemented routines */
extern Queue *queue_create(void);
extern void queue_enqueue(Queue *q, int64_t value);
extern int64_t queue_dequeue(Queue *q);
extern int64_t queue_peek(Queue *q);
extern long queue_count(Queue *q);
extern int queue_is_empty(Queue *q);
extern void queue_print(Queue *q);
extern void queue_destroy(Queue *q);

// Function to display help information
static void help(void) {
    puts("Commands:");
    puts("  enqueue <n>   Add integer n to the queue");
    puts("  dequeue       Remove & print front element");
    puts("  peek          Print front element without removing");
    puts("  print         Dump entire queue");
    puts("  count         Show number of elements");
    puts("  empty         1 if empty, 0 otherwise");
    puts("  help          Show this message");
    puts("  exit          Quit");
}

int main(int argc, char *argv[]) {
    Queue *q = queue_create();
    if (!q) {
        fprintf(stderr, "ERROR: could not create queue\n");
        return EXIT_FAILURE;
    }

    char line[128];
    help();

    while (true) {
        printf("queue> ");
        if (!fgets(line, sizeof(line), stdin))
            break;
        line[strcspn(line, "\n")] = '\0'; // strip newline

        if (strncmp(line, "enqueue ", 8) == 0) {
            // Enqueue a new value(int64_t) into the queue
            int64_t v;
            if (sscanf(line + 8, "%ld", &v) == 1) {
                queue_enqueue(q, v);
                printf("enqueued %ld\n", v);
            } else {
                puts("invalid number");
            }

        } else if (strcmp(line, "dequeue") == 0) {
            // Dequeue the front value(int64_t) from the queue
            if (queue_is_empty(q)) {
                puts("UNDERFLOW");
            } else {
                int64_t v = queue_dequeue(q);
                printf("dequeued %ld\n", v);
            }

        } else if (strcmp(line, "peek") == 0) {
            // Peek at the front value(int64_t) without removing it
            if (queue_is_empty(q)) {
                puts("EMPTY");
            } else {
                printf("front = %ld\n", queue_peek(q));
            }

        } else if (strcmp(line, "print") == 0) {
            // Print the entire queue
            // e.g., 10 -> 20 -> 30
            queue_print(q);

        } else if (strcmp(line, "count") == 0) {
            // Show the number of elements in the queue
            printf("%ld\n", queue_count(q));

        } else if (strcmp(line, "empty") == 0) {
            // Check if the queue is empty
            printf("%s\n", queue_is_empty(q) ? "YES(empty)" : "NO(not empty)");

        } else if (strcmp(line, "help") == 0) {
            // Display help information
            help();

        } else if (strcmp(line, "exit") == 0) {
            // Exit the program
            break;

        } else if (line[0] != '\0') {
            printf("unknown command: '%s'\n", line);
        }
    }

    queue_destroy(q);
    return EXIT_SUCCESS;
}
