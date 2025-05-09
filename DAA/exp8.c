#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 20
#define INF 99999

int n;               // Number of vertices
int graph[MAX][MAX]; // Cost matrix
int dist[MAX];       // Shortest distance from source
int prev[MAX];       // Previous node in shortest path
bool visited[MAX];   // Set of visited vertices

int minDistance()
{
    int min = INF, min_index;

    for (int v = 0; v < n; v++)
    {
        if (!visited[v] && dist[v] < min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int source)
{
    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = false;
        prev[i] = -1;
    }

    // Distance of source vertex from itself is always 0
    dist[source] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance();

        // Mark the picked vertex as processed
        visited[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++)
        {
            // Update dist[v] only if:
            // 1. There is an edge from u to v
            // 2. v is not in visited[]
            // 3. Total weight of path from source to v through u is smaller than current value of dist[v]
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }
}

void printPath(int destination)
{
    if (prev[destination] == -1)
    {
        printf("%d", destination + 1);
        return;
    }

    printPath(prev[destination]);
    printf(" -> %d", destination + 1);
}

void displayShortestPaths(int source)
{
    printf("\nShortest Paths from Source Vertex %d:\n\n", source + 1);
    printf("Vertex\t\tDistance\tPath\n");

    for (int i = 0; i < n; i++)
    {
        if (i != source)
        {
            printf("%d\t\t", i + 1);

            if (dist[i] == INF)
            {
                printf("INF\t\tNo path\n");
            }
            else
            {
                printf("%d\t\t%d -> ", dist[i], source + 1);
                printPath(i);
                printf("\n");
            }
        }
    }
}

int main()
{
    int source;

    printf("------------- DIJKSTRA'S ALGORITHM FOR SINGLE SOURCE SHORTEST PATHS -------------\n\n");

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Cost from vertex %d to vertex %d (0 for no edge): ", i + 1, j + 1);
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nCost Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 0)
            {
                printf("∞\t");
            }
            else
            {
                printf("%d\t", graph[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nEnter the source vertex (1 to %d): ", n);
    scanf("%d", &source);
    source--; // Convert to 0-indexed

    if (source < 0 || source >= n)
    {
        printf("Invalid source vertex!\n");
        return 1;
    }

    dijkstra(source);

    displayShortestPaths(source);

    return 0;
}