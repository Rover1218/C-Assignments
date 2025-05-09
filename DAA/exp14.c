#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int n;
int m;
int graph[MAX][MAX];
int color[MAX];

bool isSafe(int v, int c)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && color[i] == c)
        {
            return false;
        }
    }
    return true;
}

bool graphColorUtil(int v)
{
    if (v == n)
    {
        return true;
    }

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, c))
        {
            color[v] = c;

            if (graphColorUtil(v + 1))
            {
                return true;
            }

            color[v] = 0;
        }
    }

    return false;
}

bool graphColoring()
{
    for (int i = 0; i < n; i++)
    {
        color[i] = 0;
    }

    if (graphColorUtil(0) == false)
    {
        printf("\nSolution does not exist with %d colors\n", m);
        return false;
    }

    return true;
}

void displayColors()
{
    printf("\nSolution exists with %d colors.\n\n", m);
    printf("Vertex\tColor\n");
    printf("-------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\n", i + 1, color[i]);
    }

    printf("\nColor Assignments:\n");
    for (int c = 1; c <= m; c++)
    {
        printf("Color %d: ", c);
        for (int i = 0; i < n; i++)
        {
            if (color[i] == c)
            {
                printf("%d ", i + 1);
            }
        }
        printf("\n");
    }
}

int main()
{
    int e;
    int u, v;

    printf("------------- GRAPH COLORING USING BACKTRACKING -------------\n\n");

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of colors: ");
    scanf("%d", &m);

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

    printf("\nAdjacency Matrix of the Graph:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    if (graphColoring())
    {
        displayColors();
    }

    return 0;
}