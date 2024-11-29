#include <stdio.h>

void hey(char str[])
{
    int i = 0;
    while (str[i] == ' ')
    {
        i++;
    }
    while (str[i] != '\0')
    {
        putchar('[');
        while (str[i] != '\0' && str[i] != ' ')
        {
            putchar(str[i]);
            i++;
        }
        putchar(']');
        putchar('\n');
        while (str[i] == ' ')
        {
            i++;
        }
    }
}
int main()
{
    char a[50];
    printf("Enter a string: ");
    if (fgets(a, sizeof(a), stdin) != NULL)
    {
        size_t len = 0;
        while (a[len] != '\0')
            len++;
        if (len > 0 && a[len - 1] == '\n')
        {
            a[len - 1] = '\0';
        }
        hey(a);
    }
    else
    {
        printf("Error reading input.\n");
    }
    return 0;
}