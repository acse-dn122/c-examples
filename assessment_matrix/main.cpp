#include <iostream>
#include "Matrix.h"

int main()
{
    int rows = 10;
    int cols = 10;
    bool preallocate = true;
    Matrix<double> m(rows, cols, preallocate);
    for (int i = 0; i < 100; ++i)
    {
        m.values[i] = static_cast<double>(rand()) / RAND_MAX;
    }
    m.printMatrix();

    // double *values_ptr = new double[100];
    // for (int i = 0; i < 100; ++i)
    // {
    //     values_ptr[i] = static_cast<double>(rand()) / RAND_MAX;
    // }
    // Matrix<double> m(rows, cols, values_ptr);
    // m.printMatrix();
}

// g++ -std=c++11 main.cpp Matrix.cpp -o main