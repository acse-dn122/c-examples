/* When a base and derived class both have constructor and destructor functions,
the constructor functions are executed in order of derivation.
The destructor functions are executed in reverse order.
I.e. the base class constructor is executed before the constructor in the derived class.
The reverse is true for destructor functions. */

#include <iostream>
using namespace std;

class b
{
protected:
    b()
    {
        cout << "Constructing base \n";
    }

public:
    virtual ~b()
    {
        cout << "Destructing base \n";
    }
};

class d : public b
{
public:
    d()
    {
        cout << "Constructing derived \n";
    }
    ~d()
    {
        cout << "Destructing derived \n";
    }
};

int main(void)
{
    d *derived = new d(); // "Constructing base", "Constructing derived"
    cout << "------------ \n";
    b *bptr = derived;
    cout << "------------ \n";
    delete bptr; // "Destructing derived", "Destructing base"

    cout << "------------ \n";
    d derived2; // "Constructing base", "Constructing derived", "Destructing derived", "Destructing base"
    return 0;
}