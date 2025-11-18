#include <stdio.h>
#include <string.h>
#define n 5

int stack[n], top = -1;

void push(int x)
{
    if (top == n - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = x;
        printf("Added pushed %d\n", x);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("Popped %d\n", stack[top]);
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
        printf("\n");
    }
}

void checkPalindrome()
{
    char str[100], rev[100];
    int len;

    printf("Enter string/numbers: ");
    scanf("%s", str);

    len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        stack[i] = str[i];
    }

    top = len - 1;

    for (int i = 0; i < len; i++)
    {
        rev[i] = stack[top];
        top--;
    }
    rev[len] = '\0';

    if (strcmp(str, rev) == 0)
        printf("%s is palindrome\n", str);
    else
        printf("%s is not palindrome\n", str);
}

int main()
{
    int choice, value;

    do
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Palindrome\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            checkPalindrome();
            break;

        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}

