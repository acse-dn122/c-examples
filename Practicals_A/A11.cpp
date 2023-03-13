/* Write a function that concatenates two strings. Use a pointer as the argument type. Write
another swap function using a reference as the argument type. */

#include <iostream>
#include <string>
using namespace std;

string concatenate(string *str1, string *str2)
{
    string str_concat = *str1 + *str2;
    return str_concat;
}

void swap(string &str1, string &str2)
{
    string temp = str1;
    str1 = str2;
    str2 = temp;
}

int main()
{
    string str1 = "Hello ";
    string str2 = "world!";
    string str_concat = concatenate(&str1, &str2);
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str_concat << endl;

    swap(str1, str2);
    cout << str1 << endl;
    cout << str2 << endl;
    return 0;
}