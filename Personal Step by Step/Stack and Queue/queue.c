#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Queue
{
    int items[MAX];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q)
{
    return q->front == -1 || q->front > q->rear;
}

int isFull(Queue *q)
{
    return q->rear == MAX - 1;
}

void insert(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Inserted %d into the queue.\n", value);
}

int pop(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }
    return value;
}

int peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->items[q->front];
}

int main()
{
    Queue q;
    initializeQueue(&q);
    int choice, value;

    while (1)
    {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(&q, value);
            break;
        case 2:
            value = pop(&q);
            if (value != -1)
            {
                printf("Removed value: %d\n", value);
            }
            break;
        case 3:
            value = peek(&q);
            if (value != -1)
            {
                printf("Front element: %d\n", value);
            }
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
