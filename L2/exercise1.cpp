#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    cout << "INT min: " << INT_MIN << " " << INT_MAX << endl;
    cerr << "overflow " << INT_MIN - 10 << " " << INT_MAX + 10 << endl;
    return 0;
}