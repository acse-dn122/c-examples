/* Create an array D of size s=1000 doubles. Through the console, request a
number n from 1 to 10. Once read, resize the array so that its new size is
s*n. Fill the new entries of the array with random numbers between 0 and 1.
What is the size of array D? How large can it become? */

#include <iostream>
#include <cstdlib> // for rand()
#include <ctime>   // for time()

int main()
{
    const int SIZE = 100; // initial size of array
    double *arr = new double[SIZE];     // create array
    int n;                 // user input for resizing

    // fill array with random numbers between 0 and 1
    srand(time(nullptr)); // seed the random number generator
    for (int i = 0; i < SIZE; ++i)
    {
        arr[i] = static_cast<double>(rand()) / RAND_MAX; // generates a random number between 0 and 1
    }

    // prompt user to resize the array
    std::cout << "Enter a number from 1 to 10 to resize the array: ";
    std::cin >> n;

    // resize array
    if (n > 1 && n <= 10)
    {
        int new_size = SIZE * n;
        double *new_arr = new double[new_size]; // create new array with larger size
        for (int i = 0; i < SIZE; ++i)
        {
            new_arr[i] = arr[i]; // copy elements from old array to new array
        }
        for (int i = SIZE; i < new_size; ++i)
        {
            new_arr[i] = static_cast<double>(rand()) / RAND_MAX; // fill new elements with random numbers between 0 and 1
        }
        delete[] arr;          // free memory for old array
        arr = new_arr; // assign new array to old array pointer
        // double *arr = new_arr;
    }
    else
    {
        std::cout << "Invalid input. Array size remains unchanged." << std::endl;
    }

    // print the array elements
    for (int i = 0; i < SIZE * n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    // delete[] arr; // free memory for array

    return 0;
}
