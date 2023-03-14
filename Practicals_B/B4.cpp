#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<double>> matrix1(3, vector<double>(3));
    vector<vector<double>> matrix2(3, vector<double>(3));

    cout << "Enter values for matrix 1:" << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter values for matrix 2:" << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> matrix2[i][j];
        }
    }

    vector<vector<double>> result(3, vector<double>(3));
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    cout << "MATRIX 1 = [";
    for (int i = 0; i < 3; ++i)
    {
        cout << "[";
        for (int j = 0; j < 3; ++j)
        {
            cout << matrix1[i][j];
            if (j < 2)
            {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < 2)
        {
            cout << "; ";
        }
    }
    cout << "]" << endl;

    cout << "MATRIX 2 = [";
    for (int i = 0; i < 3; ++i)
    {
        cout << "[";
        for (int j = 0; j < 3; ++j)
        {
            cout << matrix2[i][j];
            if (j < 2)
            {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < 2)
        {
            cout << "; ";
        }
    }
    cout << "]" << endl;

    cout << "MATRIX 1 + MATRIX 2 = [";
    for (int i = 0; i < 3; ++i)
    {
        cout << "[";
        for (int j = 0; j < 3; ++j)
        {
            cout << result[i][j];
            if (j < 2)
            {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < 2)
        {
            cout << "; ";
        }
    }
    cout << "]" << endl;

    return 0;
}
