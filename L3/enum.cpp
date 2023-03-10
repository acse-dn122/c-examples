#include <iostream>

enum Color
{
    red,
    green,
    blue
};

Color c = red;
int a = red;

enum class Month
{
    jan = 1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};

const char *MonthToString(Month mon) throw()
{
    switch (mon)
    {
    case Month::jan:
        return "Jan";
    case Month::feb:
        return "Fed";
    case Month::mar:
        return "Mar";
    case Month::apr:
        return "Apr";
    case Month::may:
        return "May";
    case Month::jun:
        return "Jun";
    case Month::jul:
        return "Jul";
    case Month::aug:
        return "Aug";
    case Month::sep:
        return "Sep";
    case Month::oct:
        return "Oct";
    case Month::nov:
        return "Nov";
    case Month::dec:
        return "Dec";
    default:
        throw std::invalid_argument("Unimplemented item");
    }
}

Month m = Month::feb;
Month mm = Month(7);
// int b = m; // type month can not convert to int
int b = int(mm);

enum class stream_state
{
    good = 1,
    fail = 2,
    bad = 4,
    eof = 8
};

int flags = int(stream_state::fail) + int(stream_state::eof);
stream_state s = stream_state(flags);

int main()
{
    std::cout << MonthToString(mm) << std::endl;
    std::cout << int(s) << std::endl;
    return 0;
}