#include <iostream>
#include "../assessment_matrix/CSRMatrix.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> readfile(string filename)
{
    fstream file;
    file.open(filename, fstream::in);

    vector<vector<int>> matrix;

    if (file.fail())
    {
        cout << "Cannot open file" << endl;
        exit(0);
    }

    string text;
    string delimiter = " ";
    while (getline(file, text))
    {
        int pos = 0;
        string txt;
        vector<int> word;
        while ((pos = text.find(delimiter)) != std::string::npos)
        {
            txt = text.substr(0, pos);
            word.push_back(stoi(txt)); // store read txt
            text.erase(0, pos + delimiter.length());
        }

        word.push_back(stoi(text)); // store last text
        matrix.push_back(word);
    }

    file.close();

    // for (const auto &row : matrix)
    // {
    //     for (auto &col : row)
    //     {
    //         cout << col << " ";
    //     }
    //     cout << endl;
    // }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = readfile("matrix.txt");
    int rows = 10;
    int cols = 10;
    double *values_ptr = new double[100];

    int i = 0;
    for (const auto &row : matrix)
    {
        for (auto &col : row)
        {
            values_ptr[i] = col;
            ++i;
        }
    }
    Matrix<double> m(rows, cols, values_ptr);
    m.printMatrix();

    CSRMatrix<double> csr_matrix(m);
    csr_matrix.copyDropValues(10, m);
    csr_matrix.printMatrix();

    return 0;
}

// g++ -std=c++11 C3.cpp ../assessment_matrix/CSRMatrix.cpp ../assessment_matrix/Matrix.cpp -o C3