// C++ program to demonstrate
// working of erase() function
#include <iostream>
#include <vector>
#include <map>
#include <list>
using namespace std;

int main()
{
    // vector<int> myvector{1, 2, 3, 4, 5, 6, 7, 8};
    // vector<int>::iterator it, it1, it2;

    // it = myvector.begin();
    // it1 = myvector.begin() + 3;
    // it2 = myvector.begin() + 6;
    // myvector.erase(it1, it2);

    // // Printing the Vector
    // for (auto it = myvector.begin(); it != myvector.end(); ++it)
    //     cout << ' ' << *it;

    // cout << endl;

    map<double, double> m;
    while (m.size() < 10)
    {
        double r = rand() % 101;
        m[r] = r;
    }
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << " ";
    }
    cout << endl;

    // map<double, double>::iterator iter_m = m.begin();
    // advance(iter_m, 5);
    // m.erase(iter_m, m.end());

    for (auto it = next(m.begin(), 5); it != m.end();)
    {
        m.erase(it++);
    }
    cout << m.size() << endl;

    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << " ";
    }
    cout << endl;

    return 0;
}
