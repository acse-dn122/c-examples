/*
Read from a text file a sequence of (vegetable name, sow month, raised bed) tuples:

Leek March 1
Carrots April 1
Celery April 1
Melon March 1
Kohlrabi February 2
Beans March 2
Courgette March 2
Nasturtiums February 2
Cucumbers April 3
Dill April 3
Tomatoes February 3
Nasturtiums February 3

where the three entries on each line are separated by a space. Compute and print a list of
vegetables that must be sown for each month, and report in which bed they must be sown.
Your output to screen should be as follows:

Month: February
Vegetables to sow: Kohlrabi (Bed 2), Nasturtiums (Bed 2), Nasturtiums (Bed 3), Tomatoes (Bed 3)

Month: March
Vegetables to sow: Leek (Bed 1), Melon (Bed 1), Beans (Bed 2), Courgette (Bed 2)

Month: April
Vegetables to sow: Carrots (Bed 1), Celery (Bed 1), Cucumbers (Bed 3), Dill (Bed 3)
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    ifstream myFile("B7_data.txt");

    string name;
    string month;
    int bed;

    unordered_map<string, vector<pair<string, int>>> data;

    while (myFile >> name >> month >> bed)
    {
        data[month].push_back(make_pair(name, bed));
    }
    for (auto &it : data)
    {
        cout << "Month: " << it.first << endl;
        cout << "Vegetables to sow: ";
        for (auto v = it.second.begin(); v != it.second.end(); v++)
        {
            cout << v->first << " (Bed " << v->second << ")";
            if (v != it.second.end() - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
        cout << endl;
    }
    return 0;
}