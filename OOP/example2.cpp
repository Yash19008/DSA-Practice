#include <iostream>
using namespace std;

class Calculator
{
public:
    int sum(int a, int b)
    {
        return a + b;
    }
};

int main()
{
    Calculator c;
    // Message Passing Example
    cout << "Sum of 5 and 10: " << c.sum(5, 10) << endl;
}