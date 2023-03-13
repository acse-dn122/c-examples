/*
Create a function that determines whether an integer is a prime number. The code to
compute whether the number is prime does not have to be optimised. Use the following
declaration:

bool isPrime(unsigned int n)

Write a programme that computes the values of the first thousand prime numbers. In a main,
store these in an appropriate STL container so that they can be accessed rapidly. Display
the first thousand prime numbers to screen, separated by comma values. Do not compute
the prime numbers during the printing process, but rather print out the contents of your
container.
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(unsigned int n)
{
    if (n == 0 || n == 1)
    {
        return false;
    }
    for (int i = 2; i <= n / 2; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int count = 0;
    int i = 2;
    vector<int> primes;
    while (count < 1000)
    {
        if (isPrime(i))
        {
            primes.push_back(i);
            ++count;
        }
        ++i;
    }
    for (int &prime : primes)
    {
        cout << prime << " ";
    }
    cout << endl;
}