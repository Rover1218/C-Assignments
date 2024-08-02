/*#include <stdio.h>
#include <string.h>
int main()
{
    char a[1000], b[1000];
    printf("Enter string to check wheather it is palindrome or not: ");
    scanf("%s", &a);

    strcpy(b, a);
    strrev(a);
    if (strcmp(a, b) == 0)
    {
        printf("Is is a palindrome string");
    }
    else
    {
        printf("It is not a palindrome string");
    }
    return 0;
}*/
#include <stdio.h>
#include <string.h>
int main()
{
    char a[1000];
    int flag = 0, len;
    printf("Enter string to check: ");
    scanf("%s", &a);
    len = strlen(a);
    for (int i = 0; i < len; i++)
    {
        if (a[i] != a[len - i - 1])
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        printf("It is not a palindrome string");
    }
    else
    {
        printf("It is a plaindrome string");
    }
    return 0;
}