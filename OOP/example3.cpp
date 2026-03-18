#include <iostream>

using namespace std;

class A
{
private:
    string pan;

protected:
    string mobNo;

public:
    string name;

    A(string n, string mob, string panN) : name(n), mobNo(mob), pan(panN) {}

    void getPan()
    {
        cout << "PAN: " << pan << endl;
    }
    void getName()
    {
        cout << "Name: " << name << endl;
    }
};

class B : public A
{
public:
    B(string n, string mob, string panN) : A(n, mob, panN) {}
    void getMob()
    {
        cout << "Mobile: " << mobNo << endl;
    }
};

int main()
{
    B b1("Yash", "7897897897", "ASDAD546A");
    b1.getName();
    b1.getPan();
    b1.getMob();
}