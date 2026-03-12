#include <iostream>

using namespace std;

class Shape
{
    string name;

public:
    virtual void draw() = 0;
    Shape(string n) : name(n) {}

    void getName()
    {
        cout << name << endl;
    }
};

class Circle : public Shape
{
public:
    Circle(string name) : Shape(name) {}

    void draw()
    {
        cout << "Drawing Circle!" << endl;
    }
};

int main()
{
    Circle c1("Circle One");
    c1.getName();
    c1.draw();
}