/*
Create a vector with 1000 random three-letter words. Use the “find()”
algorithm to search and count entries that have three equal letters.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct equal_letters
{
    bool operator()(const string &x) const { return (x[0] == x[1] && x[1] == x[2]); }
};

int main()
{
    // const char alphanum[] =
    //     "0123456789"
    //     "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    //     "abcdefghijklmnopqrstuvwxyz";

    srand(time(0));

    vector<string> words;
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    int len = 3;

    for (int i = 0; i < 10; ++i)
    {
        string word;
        for (int i = 0; i < len; ++i)
        {
            word += letters[rand() % (sizeof(letters) - 1)];
        }
        words.push_back(word);
    }
    words.push_back("aaa");
    words.push_back("bbb");
    words.push_back("bbb");

    for (auto &word : words)
    {
        cout << word << " ";
    }
    cout << endl;

    int count = 0;
    vector<string>::iterator it = words.begin();
    while (true)
    {
        it = find_if(it, words.end(), equal_letters());
        if (it == words.end())
        {
            break;
        }
        ++it;
        ++count;
    }
    cout << "The number of entries that have three equal letters: " << count << endl;

    int countIf = count_if(words.begin(), words.end(), equal_letters());
    cout << "Validate withh count_if algorithm: " << countIf << endl;
    return 0;
}