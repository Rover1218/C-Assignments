#include <stdio.h>

int main() {
    char str1[100] = "Hello, ";
    char str2[] = "World!";
    int i, j;

    // find end of str1
    for (i = 0; str1[i] != '\0'; ++i);

    // copy str2 to str1
    for (j = 0; str2[j] != '\0'; ++j, ++i) {
        str1[i] = str2[j];
    }

    // null terminate str1
    str1[i] = '\0';

    printf("After concatenation: %s", str1);

    return 0;
}