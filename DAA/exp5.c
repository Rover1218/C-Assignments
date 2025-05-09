#include <stdio.h>
#include <limits.h>

#define MAX 100

int m[MAX][MAX];
int s[MAX][MAX];
int p[MAX];

void matrixChainOrder(int n)
{
    int i, j, k, L, q;

    for (i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    for (L = 2; L <= n; L++)
    {
        for (i = 1; i <= n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;

            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printOptimalParenthesis(int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
    }
    else
    {
        printf("(");
        printOptimalParenthesis(i, s[i][j]);
        printOptimalParenthesis(s[i][j] + 1, j);
        printf(")");
    }
}

void printCostMatrix(int n)
{
    printf("\nCost Matrix M:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j >= i)
            {
                printf("%10d ", m[i][j]);
            }
            else
            {
                printf("%10s ", "");
            }
        }
        printf("\n");
    }
}

int main()
{
    int n, i;

    printf("------------- MATRIX CHAIN MULTIPLICATION USING DYNAMIC PROGRAMMING -------------\n\n");

    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    printf("\nEnter the dimensions of matrices:\n");
    for (i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            printf("Enter dimension d%d: ", i);
        }
        else
        {
            printf("Enter dimension d%d: ", i);
        }
        scanf("%d", &p[i]);
    }

    printf("\nThe matrices are:\n");
    for (i = 1; i <= n; i++)
    {
        printf("A%d: %d x %d\n", i, p[i - 1], p[i]);
    }

    matrixChainOrder(n);

    printCostMatrix(n);

    printf("\nMinimum number of scalar multiplications: %d\n", m[1][n]);

    printf("\nOptimal Matrix Multiplication Sequence: ");
    printOptimalParenthesis(1, n);
    printf("\n");

    return 0;
}