#include <stdio.h>

int partition(int arr[], int low, int high);

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void quicksort(int arr[], int low, int high)
{
    int partionindex;
    if (low < high)
    {
        partionindex = partition(arr, low, high);
        quicksort(arr, low, partionindex - 1);
        quicksort(arr, partionindex + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    do
    {

        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

int main()
{
    int a;
    printf("Enter size of array: ");
    scanf("%d", &a);
    int arr[a];
    for (int i = 0; i < a; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Array before sorting: ");
    display(arr, a);
    quicksort(arr, 0, a - 1);
    printf("Array after sorting: ");
    display(arr, a);
    return 0;
}

// Output
// Enter size of array: 5
// Enter element 1: 5
// Enter element 2: 1
// Enter element 3: 3
// Enter element 4: 2
// Enter element 5: 4
// Array before sorting: 5 1 3 2 4
// low: 0 high: 4
// pivot: 5
// i: 1 j: 4
// 1 <= 5
// i: 2 j: 4
// 3 <= 5
// i: 3 j: 4
// 2 <= 5
// i: 4 j: 4
// 4 <= 5
// i: 5 j: 4
// 5<4
// temp=5
// 5=4
// 4=5
// 1st partition: 4 1 3 2 5
// p=4
// high: 4 p=3
// low 5 high 4
// 2nd
// low: 0 high: 3
// pivot 4
// i: 1 j: 3
// 1 <= 4
// i: 2 j: 3
// 3 <= 4
// i: 3 j: 3
// 2 <= 4
// i: 4 j: 3
// 4<3
// temp=4
// 4=2
// 2=4
// 2nd partition: 2 1 3 4 5
// p=3
// low: 0 high: 2
// pivot 2
// i: 1 j: 2
// 1 <= 2
// i: 2 j: 2
// 3 > 2
// i: 2 j: 1
// 2<1
// temp=2
// 2=1
// 1=2
// 3rd partition: 1 2 3 4 5