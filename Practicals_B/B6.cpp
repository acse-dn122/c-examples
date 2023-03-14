/*
Write a programme that reads two strings from the screen. Write a function that
concatenates the two strings and computes the length of the resulting concatenated string.
This function should not make a copy of the strings. From a main function, print the entire
operation to screen as follows:

QUESTION B.2:
STRING 1 = Johnny
STRING 2 = Rose
STRING 1 + STRING 2 = Johnny Rose
TOTAL LENGTH = 11

Your programme should be able to concatenate any two strings input by the user.
*/

#include <iostream>
#include <string>
using namespace std;

string concatenate(string *str1, string *str2)
{
    string str_concat = *str1 + " " + *str2;
    return str_concat;
}

int main()
{
    string str1, str2;
    cout << "Enter string 1: ";
    cin >> str1;
    cout << "Enter string 2: ";
    cin >> str2;
    string str_concat = concatenate(&str1, &str2);
    cout << "STRING 1 = " << str1 << endl;
    cout << "STRING 2 = " << str2 << endl;
    cout << "STRING 1 + STRING 2 = " << str_concat << endl;
    cout << "TOTAL LENGTH = " << str_concat.length() << endl;
    return 0;
}