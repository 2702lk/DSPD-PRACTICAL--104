#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL, *temp = NULL, *newnode;
    int num, count = 0;

    printf("Enter integer to add to the list (0 to stop):\n");

    while (1)
    {
        scanf("%d", &num);
        if (num == 0)
            break;

        newnode = (struct Node*) malloc(sizeof(struct Node));
        newnode->data = num;
        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else
            temp->next = newnode;

        temp = newnode;
        printf("%d added to the list.\n", num);
    }

    temp = head;
    printf("\nLinked list elements:\n");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("NULL\n");
    printf("Total number of nodes: %d\n", count);

    return 0;
}

