#include <stdio.h>
#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

void insertElement()
{
    char item;
    if (rear == MAX - 1)
    {
        printf("Queue overflow, cannot insert\n");
    }
    else
    {
        if (front == -1)
            front = 0;

        printf("Enter element to insert: ");
        scanf(" %c", &item);

        rear++;
        queue[rear] = item;
        printf("%c inserted into queue\n", item);
    }
}

void deleteElement()
{
    if (front == -1 || front > rear)
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("Deleted element: %c\n", queue[front]);
        front++;
    }
}

void displayQueue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%c ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- QUEUE OPERATIONS ---\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertElement();
            break;
        case 2:
            deleteElement();
            break;
        case 3:
            displayQueue();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

