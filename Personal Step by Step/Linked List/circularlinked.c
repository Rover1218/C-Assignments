#include <stdio.h>
#include <stdlib.h>

// Node structure for circular linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(Node **tail, int data)
{
    Node *newNode = createNode(data);
    if (*tail == NULL)
    {
        newNode->next = newNode; // Point to itself if list is empty
        *tail = newNode;
    }
    else
    {
        newNode->next = (*tail)->next;
        (*tail)->next = newNode;
    }
    printf("Inserted %d at the beginning.\n", data);
}

// Function to insert a node at the end
void insertAtEnd(Node **tail, int data)
{
    Node *newNode = createNode(data);
    if (*tail == NULL)
    {
        newNode->next = newNode; // Point to itself if list is empty
        *tail = newNode;
    }
    else
    {
        newNode->next = (*tail)->next;
        (*tail)->next = newNode;
        *tail = newNode; // Update the tail pointer
    }
    printf("Inserted %d at the end.\n", data);
}

// Function to insert at a specific position
void insertAtPosition(Node **tail, int data, int position)
{
    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }
    Node *newNode = createNode(data);
    if (*tail == NULL)
    {
        if (position == 1)
        {
            newNode->next = newNode;
            *tail = newNode;
            printf("Inserted %d at position %d.\n", data, position);
        }
        else
        {
            printf("Invalid position! List is empty.\n");
        }
        return;
    }

    Node *current = (*tail)->next;
    int count = 1;
    while (count < position - 1 && current != *tail)
    {
        current = current->next;
        count++;
    }
    if (count == position - 1)
    {
        newNode->next = current->next;
        current->next = newNode;
        if (current == *tail)
        {
            *tail = newNode; // Update tail if inserted at the end
        }
        printf("Inserted %d at position %d.\n", data, position);
    }
    else
    {
        printf("Invalid position!\n");
    }
}

// Function to delete a node from the beginning
void deleteFromBeginning(Node **tail)
{
    if (*tail == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node *head = (*tail)->next;
    if (head == *tail)
    { // Only one node in the list
        free(head);
        *tail = NULL;
    }
    else
    {
        (*tail)->next = head->next;
        free(head);
    }
    printf("Deleted from the beginning.\n");
}

// Function to delete a node from the end
void deleteFromEnd(Node **tail)
{
    if (*tail == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node *current = (*tail)->next, *prev = *tail;
    if (current == *tail)
    { // Only one node in the list
        free(current);
        *tail = NULL;
    }
    else
    {
        while (current->next != (*tail)->next)
        {
            prev = current;
            current = current->next;
        }
        prev->next = (*tail)->next;
        free(current);
        *tail = prev; // Update the tail pointer
    }
    printf("Deleted from the end.\n");
}

// Function to delete a node at a specific position
void deleteAtPosition(Node **tail, int position)
{
    if (*tail == NULL || position < 1)
    {
        printf("Invalid position or list is empty.\n");
        return;
    }

    Node *current = (*tail)->next, *prev = *tail;
    if (position == 1)
    { // Delete from beginning
        if (current == *tail)
        { // Only one node in the list
            free(current);
            *tail = NULL;
        }
        else
        {
            (*tail)->next = current->next;
            free(current);
        }
        printf("Deleted node at position 1.\n");
        return;
    }

    int count = 1;
    while (count < position && current != *tail)
    {
        prev = current;
        current = current->next;
        count++;
    }
    if (count == position)
    {
        prev->next = current->next;
        if (current == *tail)
        {
            *tail = prev; // Update tail if deleting the last node
        }
        free(current);
        printf("Deleted node at position %d.\n", position);
    }
    else
    {
        printf("Invalid position!\n");
    }
}

// Function to display the circular linked list
void displayList(Node *tail)
{
    if (tail == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *current = tail->next;
    printf("Circular Linked List: ");
    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != tail->next);
    printf("(back to head)\n");
}

// Function to search for an element in the list
void searchElement(Node *tail, int key)
{
    if (tail == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *current = tail->next;
    int position = 1;
    do
    {
        if (current->data == key)
        {
            printf("Element %d found at position %d.\n", key, position);
            return;
        }
        current = current->next;
        position++;
    } while (current != tail->next);

    printf("Element %d not found in the list.\n", key);
}

// Main function
int main()
{
    Node *tail = NULL;
    int choice, data, position;

    while (1)
    {
        printf("\nCircular Linked List Operations:\n");
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
            insertAtBeginning(&tail, data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(&tail, data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &position);
            insertAtPosition(&tail, data, position);
            break;
        case 4:
            deleteFromBeginning(&tail);
            break;
        case 5:
            deleteFromEnd(&tail);
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &position);
            deleteAtPosition(&tail, position);
            break;
        case 7:
            displayList(tail);
            break;
        case 8:
            printf("Enter element to search: ");
            scanf("%d", &data);
            searchElement(tail, data);
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
