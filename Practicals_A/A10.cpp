/*
Write a function that takes in a string and changes that string to Title Case. Title Case means
that each letter should be lower case unless it is either the first letter in the string or if the
preceding letter is a space, in which case the letter should be a capital. Allow the user to
enter a string, use the function to convert the string to Title Case and then display the result.
For example (where bold is user input):

Enter a string to convert: mAke ThIs tITle cAse

Output: Make This Title Case
*/

#include <iostream>
#include <string>
using namespace std;

void titleCase(string &input)
{
    bool capital = true;
    for (char &c : input)
    {   
        if (isspace(c)){
            capital = true;
        }
        else if (capital){
            c = toupper(c);
            capital = false;
        }
        else {
            c = tolower(c);
        }
    }
}

int main()
{
    string input;
    cout << "Endter a string: ";
    getline(cin, input);
    titleCase(input);
    cout << "Output: " << input << endl;
    return 0;
}