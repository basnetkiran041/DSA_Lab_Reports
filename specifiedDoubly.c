#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at a given position
void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = createNode(value);

    if (position < 1) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    if (position == 1) {
        newNode->next = *head;
        if (*head != NULL)
            (*head)->prev = newNode;
        *head = newNode;
        printf("Inserted %d at position 1.\n", value);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    printf("Inserted %d at position %d.\n", value, position);
}

// Delete at a given position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL || position < 1) {
        printf("Invalid operation.\n");
        return;
    }

    struct Node* temp = *head;

    if (position == 1) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        printf("Deleted %d from position 1.\n", temp->data);
        free(temp);
        return;
    }

    for (int i = 1; i < position && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("Deleted %d from position %d.\n", temp->data, position);
    free(temp);
}

// Display the list
void displayList(struct Node* head) {
    printf("Doubly Linked List: ");
    if (head == NULL) {
        printf("Empty\n");
        return;
    }

    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, value, position;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert at specified position\n");
        printf("2. Delete at specified position\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("Enter position to insert at: ");
            scanf("%d", &position);
            insertAtPosition(&head, value, position);
            break;

        case 2:
            printf("Enter position to delete from: ");
            scanf("%d", &position);
            deleteAtPosition(&head, position);
            break;

        case 3:
            displayList(head);
            break;

        case 4:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
