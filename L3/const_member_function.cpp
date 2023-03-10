#include <iostream>
using namespace std;

class Date
{
public:
    Date(int y, int m, int d); // constructor: check for valid date and

    // initialize
    void add_day(int n); // increase the Date by n days

    int day() const
    {
        return d;
    };

private:
    int y, m, d; // year, month, day
};

Date::Date(int yy, int mm, int dd) // definition; note :: “member of”
    : y{yy}, m{mm}, d{dd} {};      // note: member initializers

void Date::add_day(int n) { ++d; } // definition

int main()
{
    const Date my_birthday{2000, 8, 22};
    // my_birthday.add_day(1); // the object has type qualifiers that are not compatible with the member function
    cout << my_birthday.day() << endl;
    return 0;
}