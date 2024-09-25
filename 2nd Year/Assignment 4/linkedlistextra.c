#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAfter(struct Node **head, int target, int data)
{
    struct Node *temp = *head;
    while (temp != NULL && temp->data != target)
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {
        struct Node *newNode = createNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Inserted %d after %d.\n", data, target);
    }
    else
    {
        printf("Target %d not found.\n", target);
    }
}
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
void insertBefore(struct Node **head, int target, int data)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->data == target)
    {
        struct Node *newNode = createNode(data);
        newNode->next = *head;
        *head = newNode;
        printf("Inserted %d before %d.\n", data, target);
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL && temp->next->data != target)
    {
        temp = temp->next;
    }
    if (temp->next != NULL)
    {
        struct Node *newNode = createNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Inserted %d before %d.\n", data, target);
    }
    else
    {
        printf("Target %d not found.\n", target);
    }
}
void deleteAfter(struct Node **head, int target)
{
    struct Node *temp = *head;
    while (temp != NULL && temp->data != target)
    {
        temp = temp->next;
    }
    if (temp != NULL && temp->next != NULL)
    {
        struct Node *toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
        printf("Deleted element after %d.\n", target);
    }
    else
    {
        printf("Target %d not found or no element after target.\n", target);
    }
}
void deleteBefore(struct Node **head, int target)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        printf("List is empty or too small.\n");
        return;
    }
    if ((*head)->data == target)
    {
        printf("No element before the head.\n");
        return;
    }
    struct Node *temp = *head;
    if ((*head)->next->data == target)
    {
        struct Node *toDelete = *head;
        *head = (*head)->next;
        free(toDelete);
        printf("Deleted element before %d.\n", target);
        return;
    }
    while (temp->next != NULL && temp->next->next != NULL && temp->next->next->data != target)
    {
        temp = temp->next;
    }
    if (temp->next != NULL && temp->next->next != NULL)
    {
        struct Node *toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
        printf("Deleted element before %d.\n", target);
    }
    else
    {
        printf("Target %d not found or no element before target.\n", target);
    }
}
void sortList(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *current = *head;
    struct Node *index = NULL;
    int temp;

    while (current != NULL)
    {
        index = current->next;
        while (index != NULL)
        {
            if (current->data > index->data)
            {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
    printf("List sorted.\n");
}
void reverseList(struct Node **head)
{
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("List reversed.\n");
}
void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void menu()
{
    struct Node *head = NULL;
    int choice, target, data;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert element at the beginning\n");
        printf("2. Insert after a target element\n");
        printf("3. Insert before a target element\n");
        printf("4. Delete after a target element\n");
        printf("5. Delete before a target element\n");
        printf("6. Sort list\n");
        printf("7. Reverse list\n");
        printf("8. Display list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to insert at the beginning: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter target element: ");
            scanf("%d", &target);
            printf("Enter element to insert after target: ");
            scanf("%d", &data);
            insertAfter(&head, target, data);
            break;
        case 3:
            printf("Enter target element: ");
            scanf("%d", &target);
            printf("Enter element to insert before target: ");
            scanf("%d", &data);
            insertBefore(&head, target, data);
            break;
        case 4:
            printf("Enter target element: ");
            scanf("%d", &target);
            deleteAfter(&head, target);
            break;
        case 5:
            printf("Enter target element: ");
            scanf("%d", &target);
            deleteBefore(&head, target);
            break;
        case 6:
            sortList(&head);
            break;
        case 7:
            reverseList(&head);
            break;
        case 8:
            displayList(head);
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
        }
    }
}

int main()
{
    menu();
    return 0;
}