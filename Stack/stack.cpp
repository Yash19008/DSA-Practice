#include <iostream>
#define MAX 10

using namespace std;

int stack[MAX];
int top = -1;

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int x)
{
    if (!isFull())
    {
        top++;
        stack[top] = x;
    }
    else
    {
        printf("Cannot Insert! Stack is Full.");
    }
}

int pop()
{
    if (!isEmpty())
    {
        return stack[top--];
    }
    else
    {
        printf("Cannot Delete! Stack is already empty.");
        return -1;
    }
}

int peek()
{
    if (!isEmpty())
    {
        return stack[top];
    }
}

void printStack()
{
    if (!isEmpty())
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
}

int main()
{
    push(10);
    push(50);
    push(5);
    push(6);
    // printf("%d\n", pop());
    // printf("%d\n", peek());

    printStack();
}