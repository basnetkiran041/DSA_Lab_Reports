#include <stdio.h>
#define SIZE 5 // Set queue size

int queue[SIZE];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        printf("Queue is Full (Overflow)\n");
    }
    else
    {
        if (front == -1)
            front = 0; // First insertion
        rear++;
        queue[rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}

// Dequeue operation
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty (Underflow)\n");
    }
    else
    {
        printf("Deleted %d from the queue.\n", queue[front]);
        front++;
    }
}

// Display operation
void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        printf("Queue Elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function
int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Linear Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice! Please enter 1–4.\n");
        }
    }

    return 0;
}
