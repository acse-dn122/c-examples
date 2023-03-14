/* Part I. Create five containers: a vector, a set, an unordered_set, a map and a
multimap. Add the same 100 random entries to the containers (for the
sequences containers add the random value r, for the associative containers
add the tuple r, fact(r). */

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
using namespace std;

template <typename T>
T fact(T c)
{
    T factorial = 1;
    for (int i = 1; i <= c; i++)
    {
        factorial *= i;
    }
    return factorial;
}

int main()
{
    cout << "------Vector------" << endl;
    vector<int> vec;
    while (vec.size() < 100)
    {
        vec.push_back(rand());
    }
    for (auto &v : vec)
    {
        cout << v << " ";
    }

    cout << "\n------Set------" << endl;
    set<int> s;
    while (s.size() < 100)
    {
        s.insert(rand());
    }
    for (auto &ss : s)
    {
        cout << ss << " ";
    }

    cout << "\n------Unordered_set------" << endl;
    unordered_set<int> unordered_s;
    while (unordered_s.size() < 100)
    {
        unordered_s.insert(rand());
    }
    for (auto &u_s : unordered_s)
    {
        cout << u_s << " ";
    }

    cout << "\n------Map------" << endl;
    map<int, int> m;
    while (m.size() < 10)
    {
        int random = rand() % 11;
        m.insert(make_pair(random, fact(random)));
    }
    for (auto itr = m.begin(); itr != m.end(); ++itr)
    {
        cout << itr->first
             << '\t' << itr->second << '\n';
    }
    // for (auto &mm : m)
    // {
    //     cout << mm.first << " " << mm.second << '\n';
    // }

    cout << "\n------Multimap------" << endl;
    multimap<int, int> mul_m;
    while (mul_m.size() < 20)
    {
        int random = rand() % 11;
        mul_m.insert(make_pair(random, fact(random)));
    }
    for (auto itr = mul_m.begin(); itr != mul_m.end(); ++itr)
    {
        cout << itr->first
             << '\t' << itr->second << '\n';
    }
    return 0;
}