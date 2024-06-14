#include <stdio.h>
int main()
{
    int a, i, b;
    printf("Enter number: ");
    scanf("%d", &a);
    for (i = 1; i < 11; i++)
    {
        b = a * i;
        printf("%dx%d=%d\n", a, i, b);
    }
    return 0;
}