#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Insert at end in circular linked list
void insertNode(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (*head == NULL) {
        newNode->next = newNode; // points to itself
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = *head;
    }

    printf("Inserted %d in the list.\n", value);
}

// Delete a node by value
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *curr = *head, *prev = NULL;

    // Single node case
    if (curr->data == value && curr->next == *head) {
        *head = NULL;
        free(curr);
        printf("Deleted %d from the list.\n", value);
        return;
    }

    // If head is to be deleted
    if (curr->data == value) {
        while (curr->next != *head)
            curr = curr->next;
        curr->next = (*head)->next;
        free(*head);
        *head = curr->next;
        printf("Deleted %d from the list.\n", value);
        return;
    }

    // Search the node
    prev = *head;
    curr = (*head)->next;
    while (curr != *head && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == *head) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    prev->next = curr->next;
    free(curr);
    printf("Deleted %d from the list.\n", value);
}

// Display the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert node\n");
        printf("2. Delete node by value\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertNode(&head, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;

            case 3:
                display(head);
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
