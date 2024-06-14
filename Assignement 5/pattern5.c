#include <stdio.h>
int main()
{
    int a, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &a);
    for (i = 1; i <= a; i++)
    {
        for (j = 1; j <= a; j++)
        {
            if (i == 1 || i == a || j == 1 || j == a)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}