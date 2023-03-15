/*
You are to implement a copy constructor in the CSRMatrix class. This method takes in a
dense Matrix<T> as its only input and then initialises a sparse copy of the input matrix.

Create a CSRMatrix.cpp file and a cpp file containing a main method that populates a dense
matrix that has some zero entries, then calls the copy constructor to build a new CSRMatrix
and prints the resulting sparse matrix. When calculating the sparsity of the dense matrix, just
ignore any entries with magnitude that are below 1x10^{-13}.
*/

#include <iostream>
#include "../assessment_matrix/CSRMatrix.h"
#include <time.h>

int main()
{   
    srand(time(0));

    int rows = 10;
    int cols = 10;
    double *values_ptr = new double[100];
    for (int i = 0; i < 100; i += 6)
    {
        double random = static_cast<double>(rand()) / RAND_MAX;
        values_ptr[i] = random < 1e-13 ? 0 : random;
    }
    Matrix<double> m(rows, cols, values_ptr);
    // m.printMatrix();

    CSRMatrix<double> csr_matrix(m);
    csr_matrix.printMatrix();
}

// g++ -std=c++11 C1.cpp ../assessment_matrix/CSRMatrix.cpp ../assessment_matrix/Matrix.cpp -o C1