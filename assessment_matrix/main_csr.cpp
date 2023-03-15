#include <iostream>
#include "CSRMatrix.h"

int main()
{
    int rows = 10;
    int cols = 10;
    int nnzs = 0;
    bool preallocate = true;
    CSRMatrix<double> csr_matrix(rows, cols, nnzs, preallocate);
    csr_matrix.printMatrix();
}

// g++ -std=c++11 main_csr.cpp CSRMatrix.cpp Matrix.cpp -o main_csr