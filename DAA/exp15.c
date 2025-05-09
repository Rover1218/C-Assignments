#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 4
#define MAX_MOVES 100

typedef struct
{
    int board[N][N];
    int x, y;
    int level;
    int cost;
    int prev_move;
    struct PuzzleNode *parent;
} PuzzleNode;

typedef struct
{
    PuzzleNode *nodes[1000];
    int size;
} PriorityQueue;

void initializePriorityQueue(PriorityQueue *pq)
{
    pq->size = 0;
}

void swap(PuzzleNode **a, PuzzleNode **b)
{
    PuzzleNode *temp = *a;
    *a = *b;
    *b = temp;
}

void pushPriorityQueue(PriorityQueue *pq, PuzzleNode *node)
{
    pq->nodes[pq->size] = node;
    int current = pq->size;
    pq->size++;

    while (current > 0)
    {
        int parent = (current - 1) / 2;
        if (pq->nodes[current]->cost >= pq->nodes[parent]->cost)
        {
            break;
        }
        swap(&pq->nodes[current], &pq->nodes[parent]);
        current = parent;
    }
}

PuzzleNode *popPriorityQueue(PriorityQueue *pq)
{
    if (pq->size == 0)
    {
        return NULL;
    }

    PuzzleNode *top = pq->nodes[0];

    pq->nodes[0] = pq->nodes[pq->size - 1];
    pq->size--;

    int current = 0;
    while (true)
    {
        int leftChild = 2 * current + 1;
        int rightChild = 2 * current + 2;
        int smallest = current;

        if (leftChild < pq->size && pq->nodes[leftChild]->cost < pq->nodes[smallest]->cost)
        {
            smallest = leftChild;
        }

        if (rightChild < pq->size && pq->nodes[rightChild]->cost < pq->nodes[smallest]->cost)
        {
            smallest = rightChild;
        }

        if (smallest == current)
        {
            break;
        }

        swap(&pq->nodes[current], &pq->nodes[smallest]);
        current = smallest;
    }

    return top;
}

int calculateManhattanDistance(int board[N][N], int goal[N][N])
{
    int distance = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] != 0)
            {
                int value = board[i][j];
                for (int gi = 0; gi < N; gi++)
                {
                    for (int gj = 0; gj < N; gj++)
                    {
                        if (goal[gi][gj] == value)
                        {
                            distance += abs(i - gi) + abs(j - gj);
                            break;
                        }
                    }
                }
            }
        }
    }

    return distance;
}

PuzzleNode *createNode(int board[N][N], int x, int y, int level, int prev_move, PuzzleNode *parent, int goal[N][N])
{
    PuzzleNode *node = (PuzzleNode *)malloc(sizeof(PuzzleNode));

    memcpy(node->board, board, sizeof(node->board));
    node->x = x;
    node->y = y;
    node->level = level;
    node->prev_move = prev_move;
    node->parent = parent;

    int h = calculateManhattanDistance(board, goal);
    node->cost = level + h;

    return node;
}

bool isSafe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}

bool isGoalState(int board[N][N], int goal[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] != goal[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void printBoard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
            {
                printf("   ");
            }
            else
            {
                printf("%2d ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void printPath(PuzzleNode *node)
{
    if (node == NULL)
    {
        return;
    }

    printPath(node->parent);
    printf("Level %d:\n", node->level);
    printBoard(node->board);

    if (node->prev_move == 0)
    {
        printf("Move: Up\n\n");
    }
    else if (node->prev_move == 1)
    {
        printf("Move: Right\n\n");
    }
    else if (node->prev_move == 2)
    {
        printf("Move: Down\n\n");
    }
    else if (node->prev_move == 3)
    {
        printf("Move: Left\n\n");
    }
}

bool solvePuzzle(int initial[N][N], int goal[N][N])
{
    int blank_x = -1, blank_y = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (initial[i][j] == 0)
            {
                blank_x = i;
                blank_y = j;
                break;
            }
        }
        if (blank_x != -1)
        {
            break;
        }
    }

    PriorityQueue pq;
    initializePriorityQueue(&pq);

    PuzzleNode *root = createNode(initial, blank_x, blank_y, 0, -1, NULL, goal);
    pushPriorityQueue(&pq, root);

    int row[] = {-1, 0, 1, 0};
    int col[] = {0, 1, 0, -1};

    while (pq.size > 0)
    {
        PuzzleNode *node = popPriorityQueue(&pq);

        if (isGoalState(node->board, goal))
        {
            printf("\nSolution found at level %d!\n\n", node->level);
            printf("Path from initial state to goal state:\n\n");
            printPath(node);
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int new_x = node->x + row[i];
            int new_y = node->y + col[i];

            if (isSafe(new_x, new_y))
            {
                int new_board[N][N];
                memcpy(new_board, node->board, sizeof(new_board));

                new_board[node->x][node->y] = new_board[new_x][new_y];
                new_board[new_x][new_y] = 0;

                PuzzleNode *child = createNode(new_board, new_x, new_y, node->level + 1, i, node, goal);

                pushPriorityQueue(&pq, child);
            }
        }
    }

    printf("\nNo solution found!\n");
    return false;
}

int main()
{
    int initial[N][N], goal[N][N];

    printf("------------- 15 PUZZLE PROBLEM USING BRANCH AND BOUND -------------\n\n");

    printf("Enter the initial state of the puzzle (use 0 for blank):\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &initial[i][j]);
        }
    }

    printf("\nEnter the goal state of the puzzle (use 0 for blank):\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &goal[i][j]);
        }
    }

    printf("\nInitial State:\n");
    printBoard(initial);

    printf("Goal State:\n");
    printBoard(goal);

    printf("Solving puzzle...\n");
    solvePuzzle(initial, goal);

    return 0;
}