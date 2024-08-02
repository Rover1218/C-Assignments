#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, c, s, ar, pr;
    printf("Enter 1st side:");
    scanf("%d", &a);
    printf("Enter 2nd side:");
    scanf("%d", &b);
    printf("Enter 3rd side:");
    scanf("%d", &c);
    pr = a + b + c;
    s = pr / 2;
    ar = sqrt((s * (s - a) * (s - b) * (s - c)));
    printf("The area of triangle is: %d\n", ar);
    printf("The perimeter of the triangle is: %d", pr);
    return 0;
}