#include <iostream>
#include "CSRMatrix.h"

// Constructor - using an initialisation list here
template <class T>
CSRMatrix<T>::CSRMatrix(int rows, int cols, int nnzs, bool preallocate) : Matrix<T>(rows, cols, false), nnzs(nnzs)
{
   // If we don't pass false in the initialisation list base constructor, it would allocate values to be of size
   // rows * cols in our base matrix class
   // So then we need to set it to the real value we had passed in
   this->preallocated = preallocate;

   // If we want to handle memory ourselves
   if (this->preallocated)
   {
      // Must remember to delete this in the destructor
      this->values = new T[this->nnzs];
      this->row_position = new int[this->rows + 1];
      this->col_index = new int[this->nnzs];
   }
}

// Constructor - now just setting the value of our T pointer
template <class T>
CSRMatrix<T>::CSRMatrix(int rows, int cols, int nnzs, T *values_ptr, int *row_position, int *col_index) : Matrix<T>(rows, cols, values_ptr), nnzs(nnzs), row_position(row_position), col_index(col_index)
{
}

// converts dense matrix into sparse
template <class T>
CSRMatrix<T>::CSRMatrix(Matrix<T> &input) : Matrix<T>(input.rows, input.cols, false)
{
   // Calculate how many nnzs by iterating over all the values in the dense input and incrementing
   // the zeros counter by 1 each time we encounter a non-zero number
   this->nnzs = 0;
   for (int i = 0; i < (input.rows * input.cols); i++)
   {
      if (input.values[i] != 0)
      {
         this->nnzs++;
      }
   }
   // Declare array pointers on heap based on what we've just learnt about how many nnzs there are.
   this->values = new T[this->nnzs];
   this->row_position = new int[this->rows + 1];
   this->col_index = new int[this->nnzs];

   // Fill in row_position and col_index arrays values based on matrix
   int count = 0;
   this->row_position[0] = 0;
   for (int i = 0; i < this->rows; i++)
   {
      int nnzs_in_row = 0; // Reset the row nnzs count to zero at the start of each new row
      for (int j = 0; j < this->cols; j++)
      {
         // Only do stuff IFF we encounter a non-zero
         if (input.values[i * input.cols + j] != 0)
         {
            // Fill the values array in order of how they occur in the input matrix.
            this->values[count] = input.values[i * input.cols + j];
            // Fill in the column index at the same rate as the values array gets filled
            // with the column index at this point.
            this->col_index[count] = j;
            // Increment the nnzs in row count by one
            nnzs_in_row++;
            count++;
         }
      }
      // row position is effectively a running count of nnzs we encounter in each row.
      this->row_position[i + 1] = this->row_position[i] + nnzs_in_row; // row fill is always one index ahead
   }
}

// Copy constructor
template <class T>
CSRMatrix<T>::CSRMatrix(const CSRMatrix &old_obj): Matrix<T>(old_obj.rows, old_obj.cols, false)
{
   *this = old_obj;
   // This `new` here is now detaching our `.values` attribute from the `old_obj`'s
   // to a new slab of memory and then writing in our old_obj values to this into
   // this new slab of memory. So the `delete` called during the constructor deletes
   // this slab of memory but keeps the (dangling) pointer.
   this->values = new T[old_obj.nnzs];
   this->col_index = new int[old_obj.nnzs];
   this->row_position = new int[old_obj.rows + 1];
   for (int i = 0; i < old_obj.nnzs; ++i)
   {
      this->values[i] = old_obj.values[i];
      this->col_index[i] = old_obj.col_index[i];
   }
   for (int j = 0; j < old_obj.rows; j++)
   {
      this->row_position[j] = old_obj.row_position[j];
   }
}

// destructor
template <class T>
CSRMatrix<T>::~CSRMatrix()
{
   // Delete the values array
   if (this->preallocated)
   {
      delete[] this->row_position;
      delete[] this->col_index;
   }
   // The super destructor is called after we finish here
   // This will delete this->values if preallocated is true
}

// Explicitly print out the values in values array as if they are a matrix
template <class T>
void CSRMatrix<T>::printMatrix()
{
   std::cout << "Printing matrix" << std::endl;
   std::cout << "Values: ";
   for (int j = 0; j < this->nnzs; j++)
   {
      std::cout << this->values[j] << " ";
   }
   std::cout << std::endl;
   std::cout << "row_position: ";
   for (int j = 0; j < this->rows + 1; j++)
   {
      std::cout << this->row_position[j] << " ";
   }
   std::cout << std::endl;
   std::cout << "col_index: ";
   for (int j = 0; j < this->nnzs; j++)
   {
      std::cout << this->col_index[j] << " ";
   }
   std::cout << std::endl;
}

// Do a matrix-vector product
// output = this * input
template <class T>
void CSRMatrix<T>::matVecMult(T *input, T *output)
{
   if (input == nullptr || output == nullptr)
   {
      std::cerr << "Input or output haven't been created" << std::endl;
      return;
   }

   // Set the output to zero
   for (int i = 0; i < this->rows; i++)
   {
      output[i] = 0.0;
   }

   // Loop over each row
   for (int i = 0; i < this->rows; i++)
   {
      // Loop over all the entries in this col
      for (int val_index = this->row_position[i]; val_index < this->row_position[i + 1]; val_index++)
      {
         // This is an example of indirect addressing
         // Can make it harder for the compiler to vectorise!
         output[i] += this->values[val_index] * input[this->col_index[val_index]];
      }
   }
}

// Do matrix matrix multiplication
// output = mat_left * this
template <class T>
void CSRMatrix<T>::matMatMult(CSRMatrix<T> &mat_left, CSRMatrix<T> &output)
{

   // Check our dimensions match
   if (this->cols != output.cols)
   {
      std::cerr << "Input dimensions for matrices don't match" << std::endl;
      return;
   }

   // Check if our output matrix has had space allocated to it
   if (output.values != nullptr)
   {
      // Check our dimensions match
      if (this->rows != mat_left.cols || mat_left.rows != output.rows)
      {
         std::cerr << "Input dimensions for matrices don't match" << std::endl;
         return;
      }
   }
   // The output hasn't been preallocated, so we are going to do that
   else
   {
      std::cerr << "OUTPUT HASN'T BEEN ALLOCATED" << std::endl;
   }

   // HOW DO WE SET THE SPARSITY OF OUR OUTPUT MATRIX HERE??
}

template class CSRMatrix<int>;
template class CSRMatrix<float>;
template class CSRMatrix<double>;