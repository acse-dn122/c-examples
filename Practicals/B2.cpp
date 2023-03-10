/* Two quantities are in the golden ratio if their ratio is the same as the ratio of their sum to the
larger of the two quantities. It follows that a and b are in the golden ratio if:
(𝑎 + 𝑏)/a = 𝑎 / b= 1.618
Write a function that reads a single number, 𝑧, from the screen and computes two numbers,
𝑥 and 𝑦, such that their sum is the original input number, 𝑥 + 𝑦 = 𝑧, and they are in the
golden ratio, 𝑥⁄𝑦 = 1.618. */

#include <iostream>
using namespace std;

tuple<double, double> golden_ratio(double z)
{
    double x, y;
    y = z / 2.618;
    x = 1.618 * y;
    return make_tuple(x, y);
}

int main()
{
    double z;
    cout << "Enter a single number: ";
    cin >> z;

    auto [x, y] = golden_ratio(z); // available in C++17

    cout << "x=" << x << endl;
    cout << "y=" << y << endl;

    return 0;
}