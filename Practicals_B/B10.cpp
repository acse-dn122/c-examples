/*
A shop owner has found that her staff are not very good at working out the best way to give
out change. Write a program that allows the staff to enter the amount an item cost, as well
as the amount of money tendered. The program should then calculate the change to be
given (number of £20, £10, £5 notes and £1, 50p, 20p, 10p, 5p, 2p and 1p coins).

The amounts should be entered as floating point pounds.pence amounts (e.g. 32.65
pounds). The computer should then convert these amounts into an integer number of pence
(remember type casting).

Once the change in pence has been calculated, the program should work out the type of
change to be given by giving as many of the larger notes or coins as possible. For example,
664p change should be 1×£5, 1×£1, 1×50p, 0x20p, 1×10p, 0x5p, 2×2p and 0x1p. (A
clue: Make use of integer maths)
*/

#include <iostream>
using namespace std;

int main()
{
    double cost, tendered;
    std::cout << "Enter the cost of the item: ";
    std::cin >> cost;
    std::cout << "Enter the amount tendered: ";
    std::cin >> tendered;

    int change = static_cast<int>((tendered - cost) * 100);

    int twenties = change / 2000;
    change %= 2000;
    int tens = change / 1000;
    change %= 1000;
    int fives = change / 500;
    change %= 500;
    int ones = change / 100;
    change %= 100;
    int fifty_pence = change / 50;
    change %= 50;
    int twenty_pence = change / 20;
    change %= 20;
    int ten_pence = change / 10;
    change %= 10;
    int five_pence = change / 5;
    change %= 5;
    int two_pence = change / 2;
    change %= 2;
    int one_pence = change;

    std::cout << "Change to be given: " << (tendered - cost) << " pounds\n";
    std::cout << "Notes and coins:\n";
    std::cout << "\t" << twenties << " x £20\n";
    std::cout << "\t" << tens << " x £10\n";
    std::cout << "\t" << fives << " x £5\n";
    std::cout << "\t" << ones << " x £1\n";
    std::cout << "\t" << fifty_pence << " x 50p\n";
    std::cout << "\t" << twenty_pence << " x 20p\n";
    std::cout << "\t" << ten_pence << " x 10p\n";
    std::cout << "\t" << five_pence << " x 5p\n";
    std::cout << "\t" << two_pence << " x 2p\n";
    std::cout << "\t" << one_pence << " x 1p\n";

    return 0;
}