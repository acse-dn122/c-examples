/*
Read from a text file a sequence of (name, value, Boolean) truples, for example:

John 101.7 1
Jane 21 1
Pippa 58.78 0
John 50 0
Lawrence 103.98 1
Ellie-May 67.83 1

where the name is a single whitespace-separated word (John), the value is an integer or a
floating-point value (101.7), and the Boolean is a 1 or a 0 value. Compute and print the sum
and mean for all names for which the Boolean value is true (the mean would be =
(101.7+21+103.98+67.83)/4), and the sum and mean for all names (the mean would be =
(101.7+21+58.78+50+103.98+67.83)/6).
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream myReadFile("B5_data.txt");

    string name;
    double value;
    bool Boolean;
    
    double true_sum = 0;
    double total_sum = 0;
    int true_size = 0;
    int size = 0;

    while (myReadFile >> name >> value >> Boolean)
    {
        if (Boolean)
        {
            true_sum += value;
            ++true_size;
        }
        total_sum += value;
        ++size;
    }

    cout << "Sum and mean for all names for which the Boolean value is true:\n";
    cout << "Sum: " << true_sum << ", Mean: " << true_sum / true_size << endl;
    cout << "Sum and mean for all names:\n";
    cout << "Sum: " << total_sum << ", Mean: " << total_sum / size << endl;

    return 0;
}
