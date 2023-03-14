/*
Create a static array A of 1000 integers. Fill the new entries of the array with
random numbers between 0 and 100. How much memory does your array occupy?

Create a static array B of 1000 integers. Fill the new entries of the array with
random numbers between 1,000,000 and 10,000,000. How much more memory does 
array B occupy as compared to A?

In both, make sure to: store input from user to array and print array elements
to the screen (or to a file!)
*/
#include <iostream>

int main()
{
    int A[1000];
    for (int i = 0; i < 1000; ++i)
    {
        A[i] = rand() % 101;
    }

    // int B[1000];
    // for (int i = 0; i < 1000; ++i)
    // {
    //     B[i] = 1000000 + rand() % 9000001;
    // }

    return 0;
}