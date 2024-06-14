#include <stdio.h>
int main()
{
    int a, i, c, b = 0;
    printf("Enter number to print series: ");
    scanf("%d", &a);
    for (i = 1; i <= a; i++)
    {
        c = i * i;
        b += c;
        printf("%d^%d", i, i);
        if (i != a)
        {
            printf("+");
        }
    }
    printf("\nThe total result is: %d", b);
    return 0;
}