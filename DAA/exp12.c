#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

int board[MAX][MAX];
int n;

bool place(int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

bool queen(int col)
{
    if (col >= n)
    {
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        if (place(i, col))
        {
            board[i][col] = 1;

            if (queen(col + 1))
            {
                return true;
            }

            board[i][col] = 0;
        }
    }

    return false;
}

void displayBoard()
{
    printf("\nSolution Board:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }

    printf("\nQueens' Positions:\n");
    printf("Row\tColumn\n");
    printf("------------\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                printf("%d\t%d\n", i + 1, j + 1);
            }
        }
    }

    printf("\nChessboard Representation:\n");
    printf("  ");
    for (int i = 0; i < n; i++)
    {
        printf("%c ", 'a' + i);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", i + 1);
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                printf("Q ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main()
{
    printf("------------- N-QUEEN PROBLEM USING BACKTRACKING -------------\n\n");

    printf("Enter the number of queens (the size of the board): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid board size! Please enter a value between 1 and %d.\n", MAX);
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    if (queen(0) == false)
    {
        printf("Solution does not exist for %d-Queen problem\n", n);
        return 0;
    }

    displayBoard();

    return 0;
}