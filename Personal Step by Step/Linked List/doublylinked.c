#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int data)
{
    Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at the beginning.\n", data);
}

void insertAtEnd(int data)
{
    Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %d at the end.\n", data);
}

void insertAtPosition(int data, int position)
{
    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }
    Node *newNode = createNode(data);
    if (position == 1)
    {
        insertAtBeginning(data);
        return;
    }
    Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of range!\n");
    }
    else
    {
        newNode->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
        printf("Inserted %d at position %d.\n", data, position);
    }
}

void deleteAtBeginning()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        head = NULL;
    }
    printf("Deleted %d from the end.\n", temp->data);
    free(temp);
}

void deleteAtPosition(int position)
{
    if (position < 1 || head == NULL)
    {
        printf("Invalid position or list is empty.\n");
        return;
    }
    Node *temp = head;
    if (position == 1)
    {
        deleteAtBeginning();
        return;
    }
    for (int i = 1; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of range!\n");
    }
    else
    {
        if (temp->prev != NULL)
        {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
        printf("Deleted %d from position %d.\n", temp->data, position);
        free(temp);
    }
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void search(int data)
{
    Node *temp = head;
    int position = 1;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("Element %d found at position %d.\n", data, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found.\n", data);
}

int main()
{
    int choice, data, position;

    while (1)
    {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display List\n");
        printf("8. Search Element\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &position);
            insertAtPosition(data, position);
            break;
        case 4:
            deleteAtBeginning();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &position);
            deleteAtPosition(position);
            break;
        case 7:
            display();
            break;
        case 8:
            printf("Enter element to search: ");
            scanf("%d", &data);
            search(data);
            break;
        case 9:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
