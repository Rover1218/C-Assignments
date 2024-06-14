#include <stdio.h>
int main()
{
    int a, ar, pr;
    printf("Enter radius: ");
    scanf("%d", &a);
    ar = 3.14 * a * a;
    pr = 2 * 3.14 * a;
    printf("The area of the circle is: %d\n", ar);
    printf("The perimeter of the circle is: %d", pr);
    return 0;
}