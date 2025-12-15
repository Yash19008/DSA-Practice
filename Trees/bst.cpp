#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *createNode(int x)
{
    Node *newNode = new Node;
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        inOrder(root->left);
        inOrder(root->right);
    }
}

void postOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        inOrder(root->right);
        printf("%d ", root->data);
    }
}

int isBST(Node *root)
{
    static Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
            return 0;
        if (prev != NULL && root->data <= prev->data)
            return 0;
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

int main()
{
    struct Node *p, *p1, *p2, *p3, *p4;
    p = createNode(8);
    p1 = createNode(10);
    p2 = createNode(7);
    p3 = createNode(5);
    p4 = createNode(2);

    p->left = p2;
    p->right = p1;
    p2->left = p3;
    p3->left = p4;

    inOrder(p);
    printf("\n");
    preOrder(p);
    printf("\n");
    postOrder(p);
    printf("\n");
    printf("%d", isBST(p));
}