#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

int graph[MAX][MAX];
int n;
bool visited[MAX];

struct Queue
{
    int items[MAX];
    int front;
    int rear;
};

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isEmpty(struct Queue *q)
{
    return q->rear == -1;
}

void enqueue(struct Queue *q, int value)
{
    if (q->rear == MAX - 1)
    {
        printf("\nQueue is full!");
        return;
    }

    if (q->front == -1)
    {
        q->front = 0;
    }

    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue is empty!");
        return -1;
    }

    int item = q->items[q->front];

    if (q->front >= q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front++;
    }

    return item;
}

void bfs(int startVertex)
{
    struct Queue *q = createQueue();

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    visited[startVertex] = true;
    printf("BFS Path: %d ", startVertex + 1);
    enqueue(q, startVertex);

    while (!isEmpty(q))
    {
        int currentVertex = dequeue(q);

        for (int i = 0; i < n; i++)
        {
            if (graph[currentVertex][i] == 1 && !visited[i])
            {
                printf("%d ", i + 1);
                visited[i] = true;
                enqueue(q, i);
            }
        }
    }

    free(q);
}

void displayGraph()
{
    printf("\nAdjacency Matrix of the Graph:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int e, u, v;
    int startVertex;

    printf("------------- BREADTH-FIRST SEARCH ALGORITHM -------------\n\n");

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("\nEnter the edges (format: source destination):\n");
    for (int i = 0; i < e; i++)
    {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        u--;
        v--;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    displayGraph();

    printf("\nEnter the starting vertex (1 to %d): ", n);
    scanf("%d", &startVertex);

    startVertex--;

    if (startVertex < 0 || startVertex >= n)
    {
        printf("Invalid starting vertex!\n");
        return 1;
    }

    printf("\n");
    bfs(startVertex);
    printf("\n");

    bool allVisited = true;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            allVisited = false;
            break;
        }
    }

    if (!allVisited)
    {
        printf("\nNote: Not all vertices were visited. The graph may not be connected.\n");
    }

    return 0;
}