/*
Write a class that can store a 3x3 matrix of floating-point numbers. Write member functions
that can (1) fill the array using user input, (2) display the matrix and (3) return the trace of the
matrix (the trace of a square matrix is the sum of the elements in its diagonal).

The program should then randomly generate 100 different matrices and display the average
of the traces of these matrices. Use dynamically allocated objects to store the matrices.
Remember to free the memory when you are finished with it.
*/

#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
public:
    Matrix();
    ~Matrix();
    void fill();
    void print();
    float trace();

    float **values;
};

Matrix::Matrix()
{
    values = new float *[3];
    for (int i = 0; i < 3; ++i)
    {
        values[i] = new float[3];
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < 3; ++i)
    {
        delete[] values[i];
    }
    delete[] values;
}

void Matrix::fill()
{
    cout << "Fill the matrix" << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << "at (" << i << ", " << j << "): ";
            cin >> values[i][j];
        }
        cout << endl;
    }
}

void Matrix::print()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << values[i][j] << " ";
        }
        cout << endl;
    }
}

float Matrix::trace()
{
    return values[0][0] + values[1][1] + values[2][2];
}

int main()
{
    Matrix m;
    m.fill();
    m.print();
    cout << endl
         << m.trace() << endl;

    return 0;
}