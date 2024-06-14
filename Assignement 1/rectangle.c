#include <stdio.h>
int main()
{
    int l, b, area, perimeter;
    printf("Enter Length: ");
    scanf("%d", &l);
    printf("Enter Breadth: ");
    scanf("%d", &b);
    area = l * b;
    perimeter = 2 * (l + b);
    printf("The area is %d\n", area);
    printf("The perimeter is %d", perimeter);
    return 0;
}