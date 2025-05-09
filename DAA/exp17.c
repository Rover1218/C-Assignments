#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 20
#define INF INT_MAX

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    struct Edge *edge;
};

struct Subset
{
    int parent;
    int rank;
};

struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge *)malloc(E * sizeof(struct Edge));
    return graph;
}

int find(struct Subset subsets[], int i)
{
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
    {
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank)
    {
        subsets[yroot].parent = xroot;
    }
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compareEdges(const void *a, const void *b)
{
    struct Edge *a1 = (struct Edge *)a;
    struct Edge *b1 = (struct Edge *)b;
    return a1->weight - b1->weight;
}

void KruskalMST(struct Graph *graph)
{
    int V = graph->V;
    struct Edge result[MAX];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compareEdges);

    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));

    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E)
    {
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("\nEdges in the Minimum Spanning Tree:\n");
    printf("Edge \tWeight\n");
    int total_weight = 0;
    for (i = 0; i < e; i++)
    {
        printf("%d - %d \t%d\n", result[i].src + 1, result[i].dest + 1, result[i].weight);
        total_weight += result[i].weight;
    }
    printf("\nTotal Weight of the Minimum Spanning Tree: %d\n", total_weight);

    free(subsets);
}

int main()
{
    int V;
    int cost[MAX][MAX];
    int E = 0;

    printf("------------- KRUSKAL'S ALGORITHM FOR MINIMUM SPANNING TREE -------------\n\n");

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("\nEnter the cost adjacency matrix (enter 0 for no edge):\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("Cost from vertex %d to vertex %d: ", i + 1, j + 1);
            scanf("%d", &cost[i][j]);

            if (i < j && cost[i][j] != 0)
            {
                E++;
            }
        }
    }

    printf("\nCost Adjacency Matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (cost[i][j] == 0 && i != j)
            {
                printf("INF\t");
            }
            else
            {
                printf("%d\t", cost[i][j]);
            }
        }
        printf("\n");
    }

    struct Graph *graph = createGraph(V, E);

    int e = 0;
    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            if (cost[i][j] != 0)
            {
                graph->edge[e].src = i;
                graph->edge[e].dest = j;
                graph->edge[e].weight = cost[i][j];
                e++;
            }
        }
    }

    KruskalMST(graph);

    free(graph->edge);
    free(graph);

    return 0;
}