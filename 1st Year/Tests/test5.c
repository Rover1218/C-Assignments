#include <stdio.h>

int main()
{
    int number, largest, smallest;

    // Input the first number
    printf("Enter number 1: ");
    scanf("%d", &number);

    // Initialize the largest and smallest variables with the first number
    largest = number;
    smallest = number;

    // Input the remaining 9 numbers
    for (int i = 1; i < 10; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &number);

        // Update the largest and smallest values
        if (number > largest)
        {
            largest = number;
        }
        if (number < smallest)
        {
            smallest = number;
        }
    }

    // Display the results
    printf("Largest number is: %d\n", largest);
    printf("Smallest number is: %d\n", smallest);

    return 0;
}