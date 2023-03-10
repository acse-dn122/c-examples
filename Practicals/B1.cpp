/*
Consider the following definition of ‘metallic means’.

The metallic means (also ratios or constants) of the successive natural numbers are
the continued fractions:

Create a function with the following declaration:

double computeMetallicMean(double n)

Write a programme that computes the values of the first ten metallic means as shown in the
table.
*/

#include <cmath>
#include <iostream>

double computeMetallicMean(double n)
{
    return (n + sqrt(pow(n, 2) + 4)) / 2;
}

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        double metallic_mean = computeMetallicMean(i);
        std::cout << metallic_mean << std::endl;
    }
    return 0;
}