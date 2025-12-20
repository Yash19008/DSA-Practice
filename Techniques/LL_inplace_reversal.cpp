#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};

Node *reverse(Node *head)
{
    Node *prev = nullptr, *current = head, *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void printList(Node *head)
{
    Node *p = head;
    while (p != nullptr)
    {
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    printList(head);
    head = reverse(head);
    printList(head);

    return 0;
}
