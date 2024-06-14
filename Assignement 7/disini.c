#include <stdio.h>
#include <string.h>
#include <ctype.h>
void getsinitials(char *name);
int main()
{
    char name[100];
    printf("Entre your name: ");
    fgets(name, sizeof(name), stdin);
    printf("Your initials are: ");
    getsinitials(name);
    return 0;
}
void getsinitials(char *name)
{
    int i = 0;
    if (strlen(name) > 0 && isalpha(name[0]))
    {
        printf("%c", toupper(name[0]));
    }
    while (name[i] != '\0')
    {
        if (isspace(name[i]) != 0)
        {
            printf(".");
            printf("%c", toupper(name[i + 1]));
        }
        i++;
    }
}