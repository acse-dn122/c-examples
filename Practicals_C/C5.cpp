#include <iostream>
#include "../assessment_matrix/CSRMatrix.h"
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    int rows = 10;
    int cols = 10;
    int nnzs = 46;
    int *values_ptr = new int[nnzs]{15, 12, 14, 16, 18, 20, 22, 24,
                                    26, 28, 30, 32, 34, 36, 38, 40,
                                    42, 44, 46, 48, 50, 52, 54, 56,
                                    58, 60, 62, 64, 66, 68, 70, 72,
                                    74, 76, 78, 80, 82, 84, 86, 88,
                                    90, 92, 94, 96, 98, 30};
    int *row_position = new int[rows + 1]{0, 1, 5, 10, 15, 20, 25, 30, 35, 40, 46};
    int *col_index = new int[nnzs]{0, 2, 4, 6, 8, 0, 2, 4, 6, 8, 0, 2, 4, 6, 8, 0, 2, 4, 6, 8, 0, 2, 4,
                                   6, 8, 0, 2, 4, 6, 8, 0, 2, 4, 6, 8, 0, 2, 4, 6, 8, 0, 2, 4, 6, 8, 9};

    int *values_ptr_dense = new int[rows * cols];
    Matrix<int> m(rows, cols, values_ptr_dense);

    CSRMatrix<int> csr_matrix(rows, cols, nnzs, values_ptr, row_position, col_index);
    csr_matrix.sparse2dense(m);
    m.printMatrix();

    return 0;
}

// g++ -std=c++11 C5.cpp ../assessment_matrix/CSRMatrix.cpp ../assessment_matrix/Matrix.cpp -o C5