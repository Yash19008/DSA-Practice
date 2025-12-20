#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};

bool hasCycle(Node *head)
{
    if (head == nullptr)
        return false;

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head;

    cout << hasCycle(head) << endl;

    return 0;
}
