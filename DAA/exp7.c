#include <stdio.h>
#include <limits.h>

#define MAX 20
#define INF 99999

int n;                   // Number of cities
int cost[MAX][MAX];      // Cost matrix
int dp[MAX][1 << MAX];   // DP array for memoization
int path[MAX][1 << MAX]; // Store the path
int final_path[MAX];     // To store the final path

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int tsp(int pos, int mask)
{
    // If all cities have been visited
    if (mask == ((1 << n) - 1))
    {
        return cost[pos][0];
    }

    // If this subproblem is already solved
    if (dp[pos][mask] != -1)
    {
        return dp[pos][mask];
    }

    int ans = INF;

    // Try to go to an unvisited city
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int new_cost = cost[pos][city] + tsp(city, mask | (1 << city));
            if (new_cost < ans)
            {
                ans = new_cost;
                path[pos][mask] = city;
            }
        }
    }

    return dp[pos][mask] = ans;
}

void constructTour()
{
    int pos = 0;
    int mask = 1; // Starting from city 0

    final_path[0] = 1; // Start from city 1 (1-indexed)

    for (int i = 1; i < n; i++)
    {
        int next_city = path[pos][mask];
        final_path[i] = next_city + 1; // 1-indexed cities
        pos = next_city;
        mask |= (1 << next_city);
    }
}

int main()
{
    printf("------------- TRAVELING SALESMAN PROBLEM USING DYNAMIC PROGRAMMING -------------\n\n");

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Cost from city %d to city %d: ", i + 1, j + 1);
            scanf("%d", &cost[i][j]);

            // Replace 0 with INF for no direct path (except diagonal)
            if (i != j && cost[i][j] == 0)
            {
                cost[i][j] = INF;
            }
        }
    }

    printf("\nCost Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cost[i][j] == INF)
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

    // Initialize dp array with -1 to indicate unsolved subproblems
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            dp[i][j] = -1;
            path[i][j] = -1;
        }
    }

    int min_cost = tsp(0, 1); // Start from city 0 (mask = 1 means city 0 is visited)

    printf("\nMinimum Cost: %d\n", min_cost);

    constructTour();

    printf("\nOptimal Route: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d -> ", final_path[i]);
    }
    printf("%d\n", final_path[0]);

    return 0;
}