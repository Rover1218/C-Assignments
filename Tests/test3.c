#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char name[100];
    printf("Enter your full name: ");
    scanf("%[^\n]", name);
    printf("%c", toupper(name[0]));
    for (int i = 1; i < strlen(name); i++) {
        if (name[i] == ' ') {
            printf("%c", toupper(name[i + 1]));
        }
    }
    return 0;
}