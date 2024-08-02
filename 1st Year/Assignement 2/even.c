#include <stdio.h>
int main()
{
    int a;
    printf("Enter number: ");
    scanf("%d", &a);
    if (a == 0)
        printf("0 is not even or odd");
    while (a != 0)
    {
        if (a % 2 == 0)
        {
            printf("It is even");
            break;
        }
        else
        {
            printf("It is odd");
            break;
        }
    }
    return 0;
}