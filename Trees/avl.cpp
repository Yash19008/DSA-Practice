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

    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
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

// To find the In Order Successor of a Node
Node *inOrderSuccessor(Node *root)
{
    root = root->right;
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete a Node
Node *deleteNode(Node *n, int key)
{
    if (n == NULL)
        return NULL;

    if (key < n->data)
    {
        n->left = deleteNode(n->left, key);
    }
    else if (key > n->data)
    {
        n->right = deleteNode(n->right, key);
    }
    else
    {
        if (n->left == NULL && n->right == NULL)
        {
            delete n;
            return NULL;
        }

        if (n->left == NULL)
        {
            Node *temp = n->right;
            delete n;
            return temp;
        }

        if (n->right == NULL)
        {
            Node *temp = n->left;
            delete n;
            return temp;
        }

        Node *inSuc = inOrderSuccessor(n);
        n->data = inSuc->data;
        n->right = deleteNode(n->right, inSuc->data);
    }

    if (n == NULL)
        return n;

    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    int bf = getBalanceFactor(n);

    // LL case
    if (bf > 1 && getBalanceFactor(n->left) >= 0)
        return rightRotate(n);

    // LR case
    if (bf > 1 && getBalanceFactor(n->left) < 0)
    {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }

    // RR case
    if (bf < -1 && getBalanceFactor(n->right) <= 0)
        return leftRotate(n);

    // RL case
    if (bf < -1 && getBalanceFactor(n->right) > 0)
    {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }

    return n;
}

int main()
{
    struct Node *p;
    p = createNode(8);
    p = insert(p, 1);
    p = insert(p, 3);
    p = insert(p, 5);
    p = insert(p, 6);
    p = insert(p, 15);
    p = insert(p, 2);
    p = insert(p, 4);
    p = insert(p, 0);
    p = insert(p, 9);
    p = insert(p, 10);

    inOrder(p);
    printf("\n");
    p = deleteNode(p, 10);
    p = deleteNode(p, 15);
    p = deleteNode(p, 0);
    p = deleteNode(p, 6);
    p = deleteNode(p, 8);
    inOrder(p);
}