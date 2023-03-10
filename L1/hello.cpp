// a first program:
#include <iostream> // get the library facilities needed for now

int main()          // main() is where a C++ program starts
{
    std::string name;
    std::cout << "Hello, world!" << std::endl; // output the 13 characters Hello, world!
    std::cout << "What's your name?" << std::endl;
    std::cin >> name;
    std::cout << "Hello, " << name << "!\n";

    // followed by a new line
    return 0; // return a value indicating success
}