/*
Generate 10,000 uniformly distributed random integers in the range 1 to 50,000 and store
them in

1. a standard library vector<int>
2. a standard library list<int>
3. a standard library set<int>

Notice: At the end of the insertion each container should have the same 10,000 elements.

In each case, calculate the arithmetic mean of the elements of the vector (as if you didn’t
know it already). Time the resulting loops. Measure and report onto the screen the
performance and memory consumption of the three containers.
*/

#include <iostream>
// #include <cstdlib>
#include <random>
#include <vector>
#include <list>
#include <set>
using namespace std;

int main()
{
    cout << "------Vector------" << endl;
    vector<int> vec;
    while (vec.size() < 10000)
    {
        vec.push_back(1 + rand() % 50000);
    }
    int sum = 0;
    auto start = chrono::steady_clock::now();
    for (auto &v : vec)
    {
        sum += v;
    }
    auto end = chrono::steady_clock::now();

    cout << "Elapsed time in nanoseconds: "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
         << " ns" << endl;


    cout << "------List------" << endl;
    list<int> l;
    while (l.size() < 10000)
    {
        l.push_back(1 + rand() % 50000);
    }
    sum = 0;
    start = chrono::steady_clock::now();
    for (auto &ll : l)
    {
        sum += ll;
    }
    end = chrono::steady_clock::now();

    cout << "Elapsed time in nanoseconds: "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
         << " ns" << endl;


    cout << "------Set------" << endl;
    set<int> s;
    while (s.size() < 10000)
    {
        s.insert(1 + rand() % 50000);
    }
    sum = 0;
    start = chrono::steady_clock::now();
    for (auto &ss : s)
    {
        sum += ss;
    }
    end = chrono::steady_clock::now();

    cout << "Elapsed time in nanoseconds: "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
         << " ns" << endl;

    std::cout << "Vector size: " << vec.size() * sizeof(int) << " bytes\n";
    std::cout << "List size: " << l.size() * sizeof(int) << " bytes\n";
    std::cout << "Set size: " << s.size() * sizeof(int) << " bytes\n";

    std::cout << "Vector size: " << sizeof(vec) << " bytes\n";
    std::cout << "List size: " << sizeof(l) << " bytes\n";
    std::cout << "Set size: " << sizeof(s) << " bytes\n";
}
