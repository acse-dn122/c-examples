/* You are a child minder and the children you are looking after would like to watch a movie.
However, parents have instructed that the children should watch a movie that contains the
word “happy” in the title and lasts less than 70 minutes. Write a programme that asks the
user to enter a movie title and movie duration. The program should continue asking for a
new movie title until you find one that meets the parent’s specification (i.e., contains “happy”
and is <70 minutes long). Once you have found the appropriate movie, print an “accepted”
and “rejected” list, which shows all of the previously entered movie titles. */

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string title;
    int duration;
    std::vector<std::string> movies;
    bool not_found = true;

    while (true)
    {
        std::cout << "Enter a movie title: ";
        std::cin.ignore();
        std::getline(std::cin, title);
        std::cout << "Enter the movie duration: ";
        std::cin >> duration;
        if (title.find("happy") != std::string::npos && duration < 70)
            break;
        else
            movies.push_back(title);
    }

    std::cout << "Previously accepted movie: " << title << std::endl;
    std::cout << "Previously rejected movies: ";
    for (std::string &movie : movies)
        std::cout << movie << " ";
    std::cout << std::endl;

    return 0;
}