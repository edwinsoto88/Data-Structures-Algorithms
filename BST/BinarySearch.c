#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *parent, int data)
{
    if (parent == NULL)
    {
        return createNode(data);
    }

    if (data < parent->data)
    {
        parent->left = insert(parent->left, data);
    }
    else if (data > parent->data)
    {
        parent->right = insert(parent->right, data);
    }
    return parent;
}

bool search(struct Node *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == data)
    {
        return 1;
    }
    else if (root->data > data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
    return 0;
}

void printTree(struct Node *root, int level)
{
    if (root = NULL)
        return;
    for (int i = 0; i < level; i++)
        printf(i == level - 1 ? "|-" : " ");
    printf("%d\n", root->data);
    printTree(root->left, level + 1);
    printTree(root->right, level + 1);
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 8);
    root = insert(root, 9);
    root = insert(root, 10);

    printTree(&root, 0);

    return 0;
}