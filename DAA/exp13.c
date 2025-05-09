#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int n;
int graph[MAX][MAX];
int path[MAX];

bool isSafe(int v, int pos)
{
    if (graph[path[pos - 1]][v] == 0)
    {
        return false;
    }

    for (int i = 0; i < pos; i++)
    {
        if (path[i] == v)
        {
            return false;
        }
    }

    return true;
}

bool hamiltonianCycleUtil(int pos)
{
    if (pos == n)
    {
        if (graph[path[pos - 1]][path[0]] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    for (int v = 1; v < n; v++)
    {
        if (isSafe(v, pos))
        {
            path[pos] = v;

            if (hamiltonianCycleUtil(pos + 1))
            {
                return true;
            }

            path[pos] = -1;
        }
    }

    return false;
}

bool hamiltonianCycle()
{
    for (int i = 0; i < n; i++)
    {
        path[i] = -1;
    }

    path[0] = 0;

    if (hamiltonianCycleUtil(1) == false)
    {
        printf("\nNo Hamiltonian Cycle exists\n");
        return false;
    }

    return true;
}

void displayPath()
{
    printf("\nHamiltonian Cycle exists in the graph.\n\n");
    printf("Hamiltonian Cycle: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", path[i] + 1);
    }
    printf("%d\n", path[0] + 1);

    printf("\nGraphical representation of the Hamiltonian Cycle:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d --> ", path[i] + 1);
    }
    printf("%d\n", path[0] + 1);
}

int main()
{
    int e;
    int u, v;

    printf("------------- HAMILTONIAN CYCLE USING BACKTRACKING -------------\n\n");

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

    printf("\nAdjacency Matrix of the Graph:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    if (hamiltonianCycle())
    {
        displayPath();
    }

    return 0;
}