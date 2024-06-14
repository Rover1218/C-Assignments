#include <stdio.h>
#include <string.h>
int main()
{
    char a[1000];
    printf("Enter string: ");
    scanf("%s", &a);
    printf("The original string: %s\n", a);
    printf("Reversed string is: %s ", strrev(a));
    return 0;
}