#include <stdio.h>
void print_fibonacci(int n)
{
    int first = 0;
    int second = 1;
    int next;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", first);
        next = first + second;
        first = second;
        second = next;
    }
}

int main()
{
    int n;
    printf("Enter the number of Fibonacci numbers to print: ");
    scanf("%d", &n);
    print_fibonacci(n);

    return 0;
}