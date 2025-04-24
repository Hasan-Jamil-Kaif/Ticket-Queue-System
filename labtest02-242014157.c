// ID: 242014157
// Name: MD HASAN JAMIL KAIF
//SET-02
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct CircularQueue {
    int items[MAX_SIZE];
    int front;
    int rear;
    int count;
};

void initializeQueue(struct CircularQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

bool isFull(struct CircularQueue *q) {
    return q->count == MAX_SIZE;
}

bool isEmpty(struct CircularQueue *q) {
    return q->count == 0;
}

void enqueue(struct CircularQueue *q, int ticket) {
    if (isFull(q)) {
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = ticket;
    q->count++;
}

int dequeue(struct CircularQueue *q) {
    if (isEmpty(q)) {
        return -1;
    }
    int ticket = q->items[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->count--;
    return ticket;
}

void display(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Current queue: ");
    int i = q->front;
    int itemsPrinted = 0;

    while (itemsPrinted < q->count) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX_SIZE;
        itemsPrinted++;
    }
    printf("\n");
}

int main() {
    struct CircularQueue q;
    initializeQueue(&q);

    int n;
    scanf("%d", &n);

    char operation[10];
    int ticket;

    for (int i = 0; i < n; i++) {
        scanf("%s", operation);

        if (strcmp(operation, "enqueue") == 0) {
            scanf("%d", &ticket);
            enqueue(&q, ticket);
        } else if (strcmp(operation, "dequeue") == 0) {
            int result = dequeue(&q);
            if (result != -1) {
                printf("Dequeued ticket: %d\n", result);
            }
        } else if (strcmp(operation, "display") == 0) {
            display(&q);
        }
    }

    return 0;
}

