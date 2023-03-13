/* Write a function that swaps (exchanges the values of) two integers. Use int∗ as the
argument type. Write another swap function using int& as the argument type. */

#include <iostream>
using namespace std;

void swap1(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap2(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 1;
    int b = 2;
    // swap1(&a, &b);
    swap2(a, b);
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    return 0;
}