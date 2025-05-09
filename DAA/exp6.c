#include <stdio.h>
#include <limits.h>

#define MAX 20
#define INF 99999

int graph[MAX][MAX];
int dist[MAX][MAX];
int path[MAX][MAX];
int n;

void initializeArrays()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else if (graph[i][j] == 0)
            {
                dist[i][j] = INF;
            }
            else
            {
                dist[i][j] = graph[i][j];
            }

            if (i == j || dist[i][j] == INF)
            {
                path[i][j] = -1;
            }
            else
            {
                path[i][j] = i;
            }
        }
    }
}

void floydWarshall()
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
}

void printPath(int i, int j)
{
    if (i == j)
    {
        printf("%d", i + 1);
    }
    else if (path[i][j] == -1)
    {
        printf("No path exists");
    }
    else
    {
        printPath(i, path[i][j]);
        printf(" -> %d", j + 1);
    }
}

void displayTransitiveClosure()
{
    printf("\n\nTransitive Closure (Reachability Matrix):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
            {
                printf("0 ");
            }
            else
            {
                printf("1 ");
            }
        }
        printf("\n");
    }
}

void displayShortestPaths()
{
    printf("\nAll Pairs Shortest Paths:\n");

    printf("\nShortest Distance Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
            {
                printf("INF\t");
            }
            else
            {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nShortest Paths:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && dist[i][j] != INF)
            {
                printf("Path from %d to %d (distance = %d): ", i + 1, j + 1, dist[i][j]);
                printPath(i, j);
                printf("\n");
            }
        }
    }
}

int main()
{
    int e, u, v, w;

    printf("------------- FLOYD-WARSHALL ALGORITHM FOR ALL PAIRS SHORTEST PATHS -------------\n\n");

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

    printf("\nEnter the edges (format: source destination weight):\n");
    for (int i = 0; i < e; i++)
    {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &u, &v, &w);

        if (u < 1 || u > n || v < 1 || v > n)
        {
            printf("Invalid vertex. Vertices should be between 1 and %d. Try again.\n", n);
            i--;
            continue;
        }

        graph[u - 1][v - 1] = w;
    }

    printf("\nInput Graph (Adjacency Matrix):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }

    initializeArrays();
    floydWarshall();

    displayTransitiveClosure();
    displayShortestPaths();

    return 0;
}