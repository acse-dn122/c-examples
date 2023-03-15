/*
Create a text file “ComputerProgramming.txt” with the following text:

Computer programming is the process of designing and building an executable computer
program for accomplishing a specific computing task. Programming involves tasks such as
analysis, generating algorithms, profiling algorithms' accuracy and resource consumption,
and the implementation of algorithms in a chosen programming language commonly referred to
as coding. The source code of a program is written in one or more programming languages.
The purpose of programming is to find a sequence of instructions that will automate the
performance of a task for solving a given problem. The process of programming thus often
requires expertise in several different subjects, including knowledge of the application
domain, specialized algorithms, and formal logic. Related programming tasks include
testing, debugging, maintaining a program's source code, implementation of build systems,
and management of derived artefacts such as machine code of computer programs. These might
be considered part of the programming process, but often the term software development is
used for this larger process with the term programming, implementation, or coding reserved
for the actual writing of source code. Software engineering combines engineering techniques
with software development practices.

Write a programme that reads a file, and produces a std::map<string,int> holding each
string and the number of times that the string appears. Run the program on the
“ComputerProgramming.txt” file and print out how many times each word appears in
descending order.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main()
{
    ifstream file("B11_data.txt");
    string text;
    string delimiter = " ";
    map<string, int> word_count;
    while (getline(file, text))
    {
        int pos = 0;
        string txt;
        while ((pos = text.find(delimiter)) != std::string::npos)
        {
            txt = text.substr(0, pos);
            if (txt.back() == ',' || txt.back() == '.')
            {
                txt.pop_back();
            }
            transform(txt.begin(), txt.end(), txt.begin(), [](const char &c)
                      { return tolower(c); });
            if (word_count.find(txt) == word_count.end())
            {
                word_count[txt] = 1;
            }
            else
            {
                ++word_count[txt];
            }
            text.erase(0, pos + delimiter.length());
        }

        if (text.back() == ',' || text.back() == '.')
        {
            text.pop_back();
        }
        if (word_count.find(text) == word_count.end())
        {
            word_count[text] = 1;
        }
        else
        {
            word_count[text] += 1;
        }
    }

    file.close();

    vector<pair<string, int>> word_count_vec(word_count.begin(), word_count.end());
    sort(word_count_vec.begin(), word_count_vec.end(),
         [](const pair<string, int> &a, const pair<string, int> &b)
         { return a.second > b.second; });

    for (auto &word : word_count_vec)
    {
        cout << word.first << ": " << word.second << endl;
    }

    return 0;
}