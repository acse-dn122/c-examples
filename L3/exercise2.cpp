#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ofstream myFile;
    myFile.open("input_data.txt");
    myFile << "1,2,3,100,4,5,6,-1,0.7,16,18,21,17,15,12";
    myFile.close();

    ifstream myReadFile("input_data.txt");
    string myText;
    string delimiter = ",";
    vector<vector<int>> fileText;
    while (getline(myReadFile, myText))
    {
        int pos = 0;
        string token;
        vector<int> tokens;

        while ((pos = myText.find(delimiter)) != std::string::npos)
        {
            token = myText.substr(0, pos);
            tokens.push_back(stoi(token));
            myText.erase(0, pos + delimiter.length());
        }
        tokens.push_back(stoi(myText));
        fileText.push_back(tokens);
    }

    myReadFile.close();

    for (const vector<int> &row : fileText)
    {
        for (const int &col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}