#include <iostream>
using namespace std;

class Animal
{
public:
    void eat()
    {
        cout << "Animal Eats!" << endl;
    }
};

class Dog : public Animal
{
public:
    void eat()
    {
        cout << "Dog eats Dog Food!" << endl;
    }
};

int main()
{
    Dog d;
    d.eat();
}