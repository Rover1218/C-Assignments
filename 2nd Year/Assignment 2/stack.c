#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack OverFLow");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack UnderFLow");
        return -99999;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
int peek(struct stack *ptr, int i)
{
    if (ptr->top - i + 1 < 0)
    {
        printf("Not a valid position");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top - i + 1];
    }
}
int main()
{
    int a, b, c, j, h;
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    printf("Enter size: ");
    scanf("%d", &a);
    sp->size = a;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    printf("Stack has been created\n");
    while (1)
    {
        printf("1. Insert\n2. Pop\n3. Peek:\n");
        scanf("%d", &h);
        switch (h)
        {
        case 1:
            printf("Enter values: \n");
            for (int i = 0; i < a; i++)
            {
                scanf("%d", &c);
                push(sp, c);
            }
            break;
        case 2:
            printf("%d has been popped from the stack\n", pop(sp));
            break;
        case 3:
            for (int i = 0; i < sp->top + 1; i++)
            {
                printf("The value at index %d is %d\n", i, peek(sp, i));
            }
            break;
        default:
            printf("Invalid Input");
            break;
        }
        printf("Want to Continue: Y[1] or N[0]: ");
        scanf("%d", &b);
        if (b == 1)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    return 0;
}