#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct CircularQueue
{
    int items[MAX];
    int front;
    int rear;
} CircularQueue;

void initializeQueue(CircularQueue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(CircularQueue *q)
{
    return q->front == -1;
}

int isFull(CircularQueue *q)
{
    return (q->rear + 1) % MAX == q->front;
}

void insert(CircularQueue *q, int value)
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
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Inserted %d into the queue.\n", value);
}

int pop(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}

int peek(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->items[q->front];
}

void displayQueue(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    do
    {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    } while (i != (q->rear + 1) % MAX);
    printf("\n");
}

int main()
{
    CircularQueue q;
    initializeQueue(&q);
    int choice, value;

    while (1)
    {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
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
            displayQueue(&q);
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
