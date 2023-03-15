/*
Create a set with 1000 random three-letter words. Use the “replace()”
algorithm to search words that start with the letter “a” and replace them by the
same string but now starting with a ‘z’.
*/

#include <iostream>
#include <set>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

struct start_a
{
    bool operator()(const string &x) const { return x[0] == 'a'; }
};

int main()
{
    srand(time(0));

    set<string> words;
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    int len = 3;

    for (int i = 0; i < 10; ++i)
    {
        string word;
        for (int i = 0; i < len; ++i)
        {
            word += letters[rand() % (sizeof(letters) - 1)];
        }
        words.insert(word);
    }
    words.insert("aaa");
    words.insert("abc");

    for (auto &word : words)
    {
        cout << word << " ";
    }
    cout << endl;

    // Copy to vector
    vector<string> words_vec(words.size()); // preallocate required
    copy(words.begin(), words.end(), words_vec.begin());

    vector<string>::iterator it = words_vec.begin();
    while (true)
    {
        it = find_if(it, words_vec.end(), start_a());
        if (it == words_vec.end())
        {
            break;
        }
        cout << *it << " ";
        // *it = "z" + (*it).substr(1, 2);
        replace((*it).begin(), (*it).begin() + 1, 'a', 'z');
        cout << *it << endl;
        ++it;
    }

    // Copy back
    // copy(words_vec.begin(), words_vec.end(), words.begin()); // doesn't work!!

    for (auto &word : words_vec)
    {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}