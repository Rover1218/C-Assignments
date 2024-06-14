#include <stdio.h>
int main()

{
    int r, i;
    printf("Enter number: ");
    scanf("%d", &r);
    for (i = 1; i <= r; i++)
    {
        if (r % i == 0)
        {
            printf("The factorials are: %d\n", i);
        }
    }
    return 0;
}