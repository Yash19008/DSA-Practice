#include <iostream>

using namespace std;

class Vehicle
{
public:
    virtual void start() = 0;
    virtual void horn() = 0;
};

class Car : public Vehicle
{
public:
    void start()
    {
        cout << "Starting Car!" << endl;
    }
    void horn()
    {
        cout << "Honk!" << endl;
    }
};

class Bike : public Vehicle
{
public:
    void start()
    {
        cout << "Starting Bike!" << endl;
    }
    void horn()
    {
        cout << "Playing Horn!" << endl;
    }
};

int main()
{
    Car c;
    Bike b;

    c.start();
    b.start();
}