#include <iostream>
using namespace std;

class Date
{
public:
    class Invalid
    {
    };                         // to be used as exception
    Date(int y, int m, int d); // constructor: check for valid date and

    // initialize
    void add_day(int n); // increase the Date by n days
    int year() { return y; }
    int month() { return m; }
    int day() { return d; }

private:
    int y, m, d;                        // year, month, day
    bool is_valid(int y, int m, int d); // is (y,m,d) a valid date?
};

Date::Date(int yy, int mm, int dd) // definition; note :: “member of”
    : y{yy}, m{mm}, d{dd}          // note: member initializers
{
    if (!is_valid(y, m, d))
        throw Invalid(); // check for validity
}

void Date::add_day(int n) { ++d; } // definition
bool Date::is_valid(int y, int m, int d)
{
    if (m > 12 || m < 1)
        return false;
    else
        return true;
}

int main()
{
    Date my_birthday{2000, 8, 22};
    my_birthday.add_day(1);
    cout << my_birthday.day() << endl;
    return 0;
}