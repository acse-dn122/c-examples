/* Read (from a file or from the screen) a sequence of possibly whitespace-separated
(name,value) pairs, for example:

John 20
Jane 21
Pippa 58
John 50
Pippa 10

where the name is a single whitespace-separated word (John) and the value is an integer or
a floating-point value (20). Compute and print the sum and mean for each name (for Pippa =
58+10/2) and the sum and mean for all names ((20+21+58+50+10)/5). */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    ifstream myReadFile("A9_data.txt");
    string myText;
    string delimiter = " ";
    unordered_map<string, vector<int>> data;
    while (getline(myReadFile, myText))
    {
        int pos = myText.find(delimiter);
        string name = myText.substr(0, pos);
        int value = stoi(myText.substr(pos, -1));
        data[name].push_back(value);
    }
    myReadFile.close();

    double total_sum = 0;
    int sizes = 0;
    for (auto &[name, value] : data)
    {
        double sum = 0;
        for (int &v : value)
        {
            sum += v;
        }
        cout << name << ": sum=" << sum << " mean=" << sum / value.size() << "\n";
        total_sum += sum;
        sizes += value.size();
    }
    cout << "sum=" << total_sum << " mean=" << total_sum / sizes << "\n";
    return 0;
}