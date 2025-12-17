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

Node *insert(Node *n, int key)
{
    if (n == NULL)
        return createNode(key);

    if (key < n->data)
        n->left = insert(n->left, key);
    else if (key > n->data)
        n->right = insert(n->right, key);
    else
        return n;

    int bf = getBalanceFactor(n);

    // Case: LL
    if (bf > 1 && key < n->left->data)
        return rightRotate(n);
    // Case: RR
    if (bf < -1 && key > n->right->data)
        return leftRotate(n);
    // Case: LR
    if (bf > 1 && key > n->left->data)
    {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    // Case: RL
    if (bf < -1 && key < n->right->data)
    {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }

    return n;
}

int main()
{
    struct Node *p, *p1, *p2, *p3, *p4;
    p = createNode(8);
    insert(p, 1);
    insert(p, 3);
    insert(p, 5);
    insert(p, 6);
    insert(p, 15);
    insert(p, 2);
    insert(p, 4);
    insert(p, 0);
    insert(p, 9);
    insert(p, 10);
    inOrder(p);
}