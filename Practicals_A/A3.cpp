/* Write a function that takes in an integer and then reverses the order of the digits in the
integer. For instance, changes “12345678” to “87654321”. The main section of the program
should allow the user to enter an integer, it should then call the function to reverse the
integer’s order and display the resultant integer. */

#include <iostream>
using namespace std;

int main()
{
    // Assume read a string
    /*
    string input;
    cout << "Enter an integer: ";
    cin >> input;
    reverse(input.begin(), input.end());
    std::cout << "Reverse integer: " << input << "\n";
    */

    // Assume read an integer
    int input;
    cout << "Enter an integer: ";
    cin >> input;
    int output = 0;
    while (input != 0)
    {
        output = output * 10 + input % 10;
        input /= 10;
    }
    std::cout << "Reverse integer: " << output << "\n";

    return 0;
}