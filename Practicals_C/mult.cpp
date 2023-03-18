#include <vector>
#include "../assessment_matrix/Matrix.h"
// #include "../assessment_matrix/CSRMatrix.h"

// struct SparseMatrix {
//     std::vector<double> data;
//     std::vector<int> col_indices;
//     std::vector<int> row_ptr;
//     int n_rows, n_cols;
// };

// void sparse_matrix_multiply(const SparseMatrix& A, const SparseMatrix& B, SparseMatrix& C) {
//     // Check that the input matrices are compatible for multiplication
//     if (A.n_cols != B.n_rows) {
//         throw std::invalid_argument("Matrix dimensions are not compatible for multiplication.");
//     }

//     // Initialize output matrix dimensions
//     C.n_rows = A.n_rows;
//     C.n_cols = B.n_cols;

//     // Compute row pointers for output matrix
//     C.row_ptr.resize(C.n_rows + 1);
//     C.row_ptr[0] = 0;
//     for (int i = 1; i <= C.n_rows; i++) {
//         int nnz_in_row = 0;
//         for (int j = 0; j < A.col_indices.size(); j++) {
//             int col_idx = A.col_indices[j];
//             if (col_idx >= B.n_rows) break;
//             if (B.row_ptr[col_idx+1] > B.row_ptr[col_idx]) {
//                 nnz_in_row++;
//             }
//         }
//         C.row_ptr[i] = C.row_ptr[i-1] + nnz_in_row;
//     }

//     // Allocate memory for output matrix data and column indices
//     C.data.resize(C.row_ptr[C.n_rows]);
//     C.col_indices.resize(C.row_ptr[C.n_rows]);

//     // Compute matrix multiplication using CSR format
//     for (int i = 0; i < A.n_rows; i++) {
//         int start_A = A.row_ptr[i];
//         int end_A = A.row_ptr[i+1];
//         for (int j = start_A; j < end_A; j++) {
//             int col_idx_A = A.col_indices[j];
//             int start_B = B.row_ptr[col_idx_A];
//             int end_B = B.row_ptr[col_idx_A+1];
//             for (int k = start_B; k < end_B; k++) {
//                 int col_idx_B = B.col_indices[k];
//                 double val_A = A.data[j];
//                 double val_B = B.data[k];
//                 int idx_C = C.row_ptr[i] + k - start_B;
//                 C.data[idx_C] += val_A * val_B;
//                 C.col_indices[idx_C] = col_idx_B;
//             }
//         }
//     }
// }

int main() {
    int rows = 2;
    int cols = 3;
    int *values_ptr1 = new int[6]{1,2,3,4,5,6};
    Matrix<int> m_left(rows, cols, values_ptr1);

    int *values_ptr2 = new int[6]{1,2,3,4,5,6};
    Matrix<int> m_right(cols, rows, values_ptr2);

    int *result_ptr = new int[4];
    Matrix<int> result(rows, rows, result_ptr);
    m_right.matMatMult(m_left, result);
    m_left.printMatrix();
    m_right.printMatrix();
    result.printMatrix();

    return 0;
}

// g++ -std=c++11 mult.cpp ../assessment_matrix/Matrix.cpp -o mult
// g++ -std=c++11 mult.cpp ../assessment_matrix/CSRMatrix.cpp ../assessment_matrix/Matrix.cpp -o mult