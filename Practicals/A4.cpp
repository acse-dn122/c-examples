/* Write declarations for the following: a pointer to a character, an array of 10 integers, a
reference to an array of 10 integers, a pointer to an array of character strings, a pointer to a
pointer to a character, a constant integer, a pointer to a constant integer, and a constant
pointer to an integer. Initialize each one. */

#include <iostream>

int main()
{
    // 1. a pointer to a character
    char *ptrChar;

    // 2. an array of 10 integers
    int arrInt[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // 3. a reference to an array of 10 integers
    int(&refArrInt)[10] = arrInt;

    std::cout << "reference to array: ";
    for (int e : refArrInt)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // 4. a pointer to an array of character strings
    char strings[] = {'Y', 'I', 'P'};
    char *pStr = strings;
    
    const char *arrChar[] = {"Yip", "Cheuk", "San"};
    std::cout << "pointer to an array of character strings: ";
    for (const char *e : arrChar)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // 5. a pointer to a pointer to a character
    char ch = 'a';
    char *ptrChar1 = &ch;
    char **prtPrtChar = &ptrChar1;

    std::cout << "pointer to pointer: " << **prtPrtChar << std::endl;

    // 6. a constant integer
    const int constInt = 22;

    // 7. a pointer to a constant integer
    const int *prtConstInt = &constInt;

    // 8. a constant pointer to an integer
    int num = 10;
    int *const constPrtInt = &num;

    /*
    int const* or const int* is pointer to constant integer
    int *const is a constant pointer to integer
    const int* const is a constant pointer to constant integer
    */

    int num = 20;
    const int constInt = 20;

    const int *ptr = &constInt;
    ptr = &num;

    int *const ptr2 = &num;
    // ptr2 = &constInt; // const pointer can't point to other address

    std::cout << *ptr << std::endl;
    num = 100; // what happens if pointer to non-constant integer?
    std::cout << *ptr << std::endl;
}
