#include <iostream>
#include <cmath>

int main()
{   
    // int
    int int_num = 1;
    for (int i = 0; i < 12; ++i)
    {
        int_num *= 10;
        std::cout << int_num << std::endl;
    }

    // float
    float float_num = 1;
    for (int i = 0; i < 10; ++i)
    {
        float_num *= 100000;
        std::cout << float_num << std::endl;
    }

    // double
    double double_num = 1;
    for (int i = 0; i < 10; ++i)
    {
        double_num *= 1e40;
        std::cout << double_num << std::endl;
    }
}