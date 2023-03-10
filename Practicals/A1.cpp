/* Consider the following strings: Tokyo, Berlin, Rio, Denver, Helsinki, Nairobi. Create an STL
container to store these strings. In a main, create the vector, sort the strings in the container
into ascending alphabetic order, and display the strings to screen. Choose an appropriate
container to perform these operations. */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    // string city[] = {"Tokyo", "Berlin", "Rio", "Denver", "Helsinki", "Nairobi"};
    // int n = sizeof(city) / sizeof(city[0]);
    // sort(city, city + n);
    // for (int i = 0; i < n; ++i)
    //     cout << city[i] << "\n";

    vector<string> cities = {"Tokyo", "Berlin", "Rio", "Denver", "Helsinki", "Nairobi"};
    sort(cities.begin(), cities.end());
    for (const string &city : cities)
    {
        std::cout << city << std::endl;
    }

    return 0;
}