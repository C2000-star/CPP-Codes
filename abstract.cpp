#include <iostream>
using namespace std;
class Base
{
private:
    int a, b;

public:
    virtual void f() = 0; //Pure Virtual function
    virtual void f2() = 0;
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
    virtual void f()
    {
    }
    virtual void f2()
    {
    }
    void print(int a)
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
    // Cannot make object of class Base
    // Base base;
    Derived d;
    b = &d;
    b->print();
    return 0;
}