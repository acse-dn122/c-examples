/* Write a function that takes in a string and then reverses the order of the characters in the
string. For instance, changes “diagonal” to “lanogaid”. The main section of the program
should allow the user to enter a string, it should then call the function to reverse the string’s
order and display the resultant string. */

#include <iostream>
using namespace std;

void reverseString(string &input)
{
    int len = input.length();

    for (int i = 0; i < len / 2; ++i)
    {
        swap(input[i], input[len - i - 1]);
    }
}

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;
    reverseString(input);
    std::cout << "Reversed string: " << input << "\n";
    return 0;
}