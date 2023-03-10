/* Consider the following integers: 9, 8, 7, 6, 5, 4, 3, 2, 1, 0. Use a container defined in the
Standard Template Library to store these numbers. Write a single function that: removes all
even numbers, sorts the numbers in the container into ascending order, and displays the
numbers to screen. Choose an appropriate container to perform these operations. */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void remove_even(vector<int> &nums)
{
    nums.erase(remove_if(nums.begin(), nums.end(), [](int i)
                         { return i % 2 == 0; }),
               nums.end());
}

int main()
{
    vector<int> nums = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    remove_even(nums);
    sort(nums.begin(), nums.end());
    for (const int &num : nums)
    {
        cout << num << endl;
    }

    return 0;
}
