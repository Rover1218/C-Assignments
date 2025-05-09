#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

int graph[MAX][MAX];
int n;
bool visited[MAX];

void dfs(int startVertex)
{
    visited[startVertex] = true;
    printf("%d ", startVertex + 1);

    for (int i = 0; i < n; i++)
    {
        if (graph[startVertex][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
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

    printf("------------- DEPTH-FIRST SEARCH ALGORITHM -------------\n\n");

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

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    printf("\nDFS Path: ");
    dfs(startVertex);
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