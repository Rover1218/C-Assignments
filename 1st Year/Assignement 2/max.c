#include <stdio.h>
int main()
{
    int a, b;
    printf("Enter 1st number:");
    scanf("%d", &a);
    printf("Enter 2nd number:");
    scanf("%d", &b);
    if (a > b)
    {
        printf("%d is maximum\n", a);
        printf("%d is minimum\n", b);
    }
    else
    {
        printf("%d is maximum\n", b);
        printf("%d is minimum\n", a);
    }
    return 0;
}