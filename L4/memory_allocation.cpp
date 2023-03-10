#include <iostream>

int main()
{
    int *P;
    P = new int;
    *P = 24;
    std::cout << "Value before delete: " << std::endl;
    std::cout << P << " ";
    std::cout << *P << std::endl;
    delete P;
    std::cout << "Value after delete: " << std::endl;
    std::cout << P << " ";
    std::cout << *P << std::endl;

    int *Q;
    Q = new int[20];
    Q[0] = 1;
    Q[1] = 2;
    Q[12] = 24;
    std::cout << "Value before delete: " << std::endl;
    std::cout << Q << std::endl;
    std::cout << *Q << std::endl;
    std::cout << *(Q + 1) << std::endl;
    delete[] Q;
    std::cout << "Value after delete: " << std::endl;
    std::cout << Q << std::endl;
    std::cout << *Q << std::endl;
    std::cout << *(Q + 1) << std::endl;

    return 0;
}