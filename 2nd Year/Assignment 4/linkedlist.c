#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *insertbeg(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
struct Node *insertend(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL)
    {
        return ptr;
    }
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    return head;
}
void display(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
void search(struct Node *ptr, int key)
{
    int pos = 1;
    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        ptr = ptr->next;
        pos++;
    }
    printf("Element %d not found\n", key);
}
int main()
{
    struct Node *head = NULL;
    int choice, data;
    while (1)
    {
        printf("\nEnter Choice:\n 1: Insert at Beginning\n 2: Insert at End\n 3: Display the list\n 4: Search an Element in the list\n 5: Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to insert at the beginning: ");
            scanf("%d", &data);
            head = insertbeg(head, data);
            break;
        case 2:
            printf("Enter data to insert at the end: ");
            scanf("%d", &data);
            head = insertend(head, data);
            break;
        case 3:
            display(head);
            break;
        case 4:
            printf("Enter element to search: ");
            scanf("%d", &data);
            search(head, data);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid input\n");
        }
    }
    return 0;
}