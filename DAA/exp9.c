#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 20
#define INF 99999

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    struct Edge *edge;
};

struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge *)malloc(E * sizeof(struct Edge));
    return graph;
}

void bellmanFord(struct Graph *graph, int src, int dist[], int prev[])
{
    int V = graph->V;
    int E = graph->E;

    // Initialize distances from src to all other vertices as INFINITE
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        prev[i] = -1;
    }
    dist[src] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 1; i < V; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;

            if (dist[u] != INF && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                prev[v] = u;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;

        if (dist[u] != INF && dist[u] + weight < dist[v])
        {
            printf("\nGraph contains negative weight cycle\n");
            return;
        }
    }
}

void printPath(int prev[], int dest)
{
    if (dest == -1)
    {
        return;
    }

    if (prev[dest] == -1)
    {
        printf("%d", dest + 1);
        return;
    }

    printPath(prev, prev[dest]);
    printf(" -> %d", dest + 1);
}

void displayShortestPaths(int dist[], int prev[], int src, int V)
{
    printf("\nShortest Paths from Source Vertex %d:\n\n", src + 1);
    printf("Vertex\t\tDistance\tPath\n");

    for (int i = 0; i < V; i++)
    {
        if (i != src)
        {
            printf("%d\t\t", i + 1);

            if (dist[i] == INF)
            {
                printf("INF\t\tNo path\n");
            }
            else
            {
                printf("%d\t\t%d", dist[i], src + 1);
                if (prev[i] != -1)
                {
                    printf(" -> ");
                    printPath(prev, i);
                }
                printf("\n");
            }
        }
    }
}

int main()
{
    int V, E, source;
    int cost[MAX][MAX];

    printf("------------- BELLMAN-FORD ALGORITHM FOR SINGLE SOURCE SHORTEST PATHS -------------\n\n");

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("\nEnter the cost adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("Cost from vertex %d to vertex %d: ", i + 1, j + 1);
            scanf("%d", &cost[i][j]);
        }
    }

    // Count the number of edges
    E = 0;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i != j && cost[i][j] != 0)
            {
                E++;
            }
        }
    }

    struct Graph *graph = createGraph(V, E);

    // Add all edges to the graph
    int e = 0;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i != j && cost[i][j] != 0)
            {
                graph->edge[e].src = i;
                graph->edge[e].dest = j;
                graph->edge[e].weight = cost[i][j];
                e++;
            }
        }
    }

    printf("\nCost Matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (cost[i][j] == 0 && i != j)
            {
                printf("∞\t");
            }
            else
            {
                printf("%d\t", cost[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nEnter the source vertex (1 to %d): ", V);
    scanf("%d", &source);
    source--; // Convert to 0-indexed

    if (source < 0 || source >= V)
    {
        printf("Invalid source vertex!\n");
        return 1;
    }

    int dist[V];
    int prev[V];

    bellmanFord(graph, source, dist, prev);

    displayShortestPaths(dist, prev, source, V);

    free(graph->edge);
    free(graph);

    return 0;
}