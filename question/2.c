#include <stdio.h>

int main()
{
    int i, j, row, col, rowSum, colSum;
    row = 3;
    col = 3;
    int matrix[row+1][col+1];
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("Element position [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Matrix:\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    // row-wise sum
    for (i = 0; i < row; i++)
    {
        rowSum = 0;
        for (j = 0; j < col; j++)
        {
            rowSum += matrix[i][j];
        }
        matrix[i][col] = rowSum;
    }
    // col-wise sum
    for (j = 0; j < col; j++)
    {
        colSum = 0;
        for (i = 0; i < row; i++)
        {
            colSum += matrix[i][j];
        }
        matrix[row][j] = colSum;
    }
    printf("Matrix:\n");
    for (i = 0; i <=row; i++)
    {
        for (j = 0; j <=col; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}