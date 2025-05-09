#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 20
#define INF INT_MAX

int graph[MAX][MAX];
int n;

void primMST()
{
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];

    for (int i = 0; i < n; i++)
    {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++)
    {
        int min = INF, min_index;

        for (int v = 0; v < n; v++)
        {
            if (mstSet[v] == false && key[v] < min)
            {
                min = key[v];
                min_index = v;
            }
        }

        mstSet[min_index] = true;

        for (int v = 0; v < n; v++)
        {
            if (graph[min_index][v] && mstSet[v] == false && graph[min_index][v] < key[v])
            {
                parent[v] = min_index;
                key[v] = graph[min_index][v];
            }
        }
    }

    printf("\nEdges in the Minimum Spanning Tree:\n");
    printf("Edge \tWeight\n");
    int total_weight = 0;
    for (int i = 1; i < n; i++)
    {
        printf("%d - %d \t%d\n", parent[i] + 1, i + 1, graph[i][parent[i]]);
        total_weight += graph[i][parent[i]];
    }
    printf("\nTotal Weight of the Minimum Spanning Tree: %d\n", total_weight);
}

void displayGraph()
{
    printf("\nCost Adjacency Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == INF)
            {
                printf("INF\t");
            }
            else
            {
                printf("%d\t", graph[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    printf("------------- PRIM'S ALGORITHM FOR MINIMUM SPANNING TREE -------------\n\n");

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix (enter 0 for no edge):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Cost from vertex %d to vertex %d: ", i + 1, j + 1);
            scanf("%d", &graph[i][j]);
            if (i != j && graph[i][j] == 0)
            {
                graph[i][j] = INF;
            }
        }
    }

    displayGraph();

    primMST();

    return 0;
}