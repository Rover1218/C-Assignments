#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch, a;

    printf("Enter a character: ");
    scanf("%c", &ch);

    if (isupper(ch))
    {
        printf("%c is an uppercase letter.\n", ch);
    }
    else if (islower(ch))
    {
        printf("%c is a lowercase letter.\n", ch);
        a = toupper(ch);
        printf("The upper case of this character is: %c", a);
    }
    else
    {
        printf("%c is not a letter.\n", ch);
    }

    return 0;
}
