/*
Part 1. Consider the function

int fact(int c)
{
    int factorial = 1;
    for (int i = 1; i <= c; i++)
    {
        factorial *= i;
    }
    return factorial;
}

Create a main function that prints the first 100 factorials to screen.
*/

#include <iostream>
using namespace std;

int fact(int c)
{
    int factorial = 1;
    for (int i = 1; i <= c; i++)
    {
        factorial *= i;
    }
    return factorial;
}

int main()
{
    for (int i = 0; i < 100; ++i)
    {
        cout << fact(i) << " ";
    }
    cout << endl;
    return 0;
}