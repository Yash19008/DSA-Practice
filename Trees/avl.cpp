#include <iostream>

using namespace std;

struct Node
{
    int data;
    int height;
    Node *left, *right;
};

// Creation of a Node
Node *createNode(int x)
{
    Node *newNode = new Node;
    newNode->data = x;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int getHeight(Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

int getBalanceFactor(Node *n)
{
    if (n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *tmp = y->left;

    y->left = x;
    x->right = tmp;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return y;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *tmp = x->right;

    x->right = y;
    y->left = tmp;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// In Order Traversal: L-Root-R
void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    struct Node *p, *p1, *p2, *p3, *p4;
    p = createNode(8);
}