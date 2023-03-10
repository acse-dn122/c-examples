#include <iostream>
#include <limits.h>
using namespace std;

int x; // global variable – avoid those where you can
int y; // another global variable

void f()
{
    int x; // local variable (Note – now there are two x’s)
    x = 7; // local x, not the global x
    {
        int x = y; // another local x, initialized by the global y
        // (Now there are three x’s)
        ++x; // increment the local x in this scope
        cout << x << "\n";
    }
    cout << x << "\n";
}

int main()
{
    f();
    return 0;
}