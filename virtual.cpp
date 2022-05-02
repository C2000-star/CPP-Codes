#include <iostream>
using namespace std;
class Base
{
private:
    int a, b;

public:
    virtual void print()
    {
        std::cout << "Base" << std::endl;
    }
};
class Derived : public Base
{
private:
    float eyes;

public:
    void print()
    {
        std::cout << "Derived" << std::endl;
    }
};

int main()
{
    //Error: Object of type Base cannot be assigned to Class Derived pointer.
    // Derived *d;
    // Base b;
    // d = &b;
    // d->print();
    Base *b;
    Derived d;
    b = &d;
    b->print();
    return 0;
}