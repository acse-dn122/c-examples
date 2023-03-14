#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<double> vec1, vec2;
    double num;

    cout << "Enter values for vector 1: ";
    while (cin >> num)
    {
        vec1.push_back(num);
        if (cin.get() == '\n')
        {
            break;
        }
    }

    cout << "Enter values for vector 2: ";
    while (cin >> num)
    {
        vec2.push_back(num);
        if (cin.get() == '\n')
        {
            break;
        }
    }

    if (vec1.size() != vec2.size())
    {
        cerr << "Error: Vectors must have same size." << endl;
        return 1;
    }

    vector<double> result(vec1.size());
    // transform(vec1.begin(), vec1.end(), vec2.begin(), result.begin(), plus<double>());
    for (int i = 0; i < vec1.size(); ++i)
    {
        result[i] = vec1[i] + vec2[i];
    }

    cout << "VECTOR 1 = [";
    for (int i = 0; i < vec1.size(); ++i)
    {
        cout << vec1[i];
        if (i < vec1.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "VECTOR 2 = [";
    for (int i = 0; i < vec2.size(); ++i)
    {
        cout << vec2[i];
        if (i < vec2.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "VECTOR 1 + VECTOR 2 = [";
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i];
        if (i < result.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
