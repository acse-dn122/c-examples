#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

void readfile(string filename)
{
    fstream file;
    file.open(filename, fstream::in);
    string input_name;
    string input_num;
    string input_bool;

    // map<string, vector<double>> data;
    map<string, pair<double, int>> data;
    // unordered_map<string, vector<pair<string, int>>> data;

    if (file.fail())
    {
        cout << "Cannot open file" << endl;
        exit(0);
    }

    while (!file.eof())
    {
        getline(file, input_name, ' ');          // get name
        getline(file, input_num, ' ');           // get the number
        getline(file, input_bool);               // get the bool
        if (data.find(input_name) == data.end()) // if key doesnt exist
        {
            cout << input_name << input_num << input_bool << endl;
            data.insert({input_name, {stod(input_num), stoi(input_bool)}}); // add the name to map and initialise the vector with count=1, number
        }
        else // if key exists accumulate
        {
            data[input_name].first += stod(input_num);
            data[input_name].second += stoi(input_bool);
        }
    }

    for (const auto &[name, value_count] : data)
    {
        const double sum = value_count.first;
        const int count = value_count.second;
        std::cout << "  " << name << ":\n";
        std::cout << "    Sum: " << sum << '\n';
        std::cout << "    Count: " << count << '\n';
    }
}

int main()
{
    readfile("readfile.txt");
    return 0;
}

// g++ -std=c++17 readfile.cpp -o readfile