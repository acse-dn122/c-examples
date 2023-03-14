/*
Part 2. Generalise the function so that it has a template parameter

template<typename T>
T fact(T c)

Change your main function to call fact with the following parameters:
int, long long, double, long double.
Print the first 100 factorials to screen. What has changed?
*/

#include <iostream>
using namespace std;

template <typename T>
T fact(T c)
{
    T factorial = 1;
    for (int i = 1; i <= c; i++)
    {
        factorial *= i;
    }
    return factorial;
}

int main()
{
    cout << "------int------\n ";
    for (int i = 0; i < 100; ++i)
    {
        cout << fact(i) << " ";
    }
    cout << endl;

    cout << "------long long------\n ";
    for (long long i = 0; i < 100; ++i)
    {
        cout << fact(i) << " ";
    }
    cout << endl;

    cout << "------double------\n ";
    for (double i = 0; i < 100; ++i)
    {
        cout << fact(i) << " ";
    }
    cout << endl;

    cout << "------long double------\n ";
    for (long double i = 0; i < 100; ++i)
    {
        cout << fact(i) << " ";
    }
    cout << endl;
    return 0;
}
