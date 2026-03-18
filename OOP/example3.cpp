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
private:
    string aadhar;

public:
    B(string n, string mob, string panN, string aNo) : A(n, mob, panN), aadhar(aNo) {}
    void getMob()
    {
        cout << "Mobile: " << mobNo << endl;
    }
    void getAadhar()
    {
        cout << "Aadhar No.: " << aadhar << endl;
    }
};

int main()
{
    B b1("Yash", "7897897897", "ASDAD546A", "789789456456");
    b1.getName();
    b1.getMob();
    b1.getPan();
    b1.getAadhar();
}