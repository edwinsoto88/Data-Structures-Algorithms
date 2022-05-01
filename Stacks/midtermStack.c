#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char *data;
    struct Node *link;
};

int counterSize = 0;
struct Node *top = NULL;

// Utility function to check if the stack is empty or not
int isEmpty(struct Node *top)
{
    return top == NULL;
}

// Utility function to return the top element of the stack
int peekTop(struct Node *top)
{
    if (!isEmpty(top))
    {
        return top->data;
    }
    else
    {
        printf("Stack is empty\n");
        exit(0);
    }
}

void Push(struct Node **top, int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));

    if (!temp)
    {
        exit(-1);
    }
    printf("Inserting %d\n", x);

    temp->data = x;
    temp->link = *top;
    *top = temp;
    counterSize++; // increases the size counter
}

void Pop()
{
    struct Node *temp;
    if (top == NULL)
        return;
    temp = top;
    top = top->link;
    free(temp);
    counterSize--;
}

// Utility function to return the size of the stack
int stackSize()
{
    return counterSize;
}

int main()
{
    struct Node *top = NULL;

    Push(&top, 1);
    Push(&top, 2);
    Push(&top, 3);
    Push(&top, 6);
    Push(&top, 5);
    Push(&top, 8);

    printf("\n");
    printf("The top element is %d\n", peekTop(top));      // Looks the top of the stack
    printf("The size of the stack is %d\n", stackSize()); // Calculates the size of the stack

    Pop(&top);
    Pop(&top);
    Pop(&top);

    if (isEmpty(top))
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The stack is not empty\n");
    }

    return 0;
}
