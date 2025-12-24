#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

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

Node *buildTree(int *nums, int left, int right)
{
    if (left > right)
        return NULL;

    int mid = left + (right - left) / 2;

    Node *newNode = new Node;
    newNode->data = nums[mid];

    newNode->left = buildTree(nums, left, mid - 1);
    newNode->right = buildTree(nums, mid + 1, right);

    return newNode;
}

int main()
{
    int nums[] = {3, 9, 20, 30, 45, 48, 62, 69};
    int n = sizeof(nums) / sizeof(nums[0]);
    Node *root = buildTree(nums, 0, n - 1);

    inOrder(root);
}