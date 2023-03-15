/*
Fibonacci numbers Fn, form a sequence, called the Fibonacci sequence, such that each
number is the sum of the two preceding ones, starting from 0 and 1. That is,

F0 = 0

F1 = 1

and for n> 1:

Fn = Fn-1 + Fn-2

Use standard library containers and functions to compute a sequence of the first 100 Fibonacci
numbers. Do not use recursion (a recursive function is a function that calls itself). Instead,
store Fibonacci numbers in a std::map as you compute them and reuse information in this
map to compute future numbers. Print the 100 Fibonacci sequence to a text file.
*/

#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, size_t> fibonacci;
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for (int i = 2; i < 100; ++i)
    {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
    for (auto &f : fibonacci)
    {
        cout << f.first << " " << f.second << endl;
    }
    return 0;
}