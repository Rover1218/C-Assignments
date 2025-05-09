#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key)
{
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }

    if (arr[mid] > key)
    {
        return binarySearch(arr, low, mid - 1, key);
    }

    return binarySearch(arr, mid + 1, high, key);
}

void displayResult(int position, int key)
{
    if (position == -1)
    {
        printf("\nElement %d was not found in the array.\n", key);
    }
    else
    {
        printf("\nElement %d was found at position %d (index %d).\n", key, position + 1, position);
    }
}

int main()
{
    int n, key, result;

    printf("------------- BINARY SEARCH USING DIVIDE & CONQUER -------------\n\n");

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("\nEnter %d sorted integers in ascending order:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            printf("\nError: The array is not sorted in ascending order!\n");
            printf("Please restart the program and enter a sorted array.\n");
            return 1;
        }
    }

    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, 0, n - 1, key);

    displayResult(result, key);

    return 0;
}