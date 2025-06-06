#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at a given position
void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = createNode(value);

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("Inserted %d at position 1.\n", value);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Position out of range!\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", value, position);
}

// Delete at a given position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position == 1) {
        struct Node* temp = *head;
        *head = (*head)->next;
        printf("Deleted %d from position 1.\n", temp->data);
        free(temp);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Position out of range!\n");
            return;
        }
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    printf("Deleted %d from position %d.\n", toDelete->data, position);
    free(toDelete);
}

// Display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked list: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function with menu
int main() {
    struct Node* head = NULL;
    int choice, value, position;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert at specific position\n");
        printf("2. Delete at specific position\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, value, position);
                break;

            case 2:
                printf("Enter position to delete: ");
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
