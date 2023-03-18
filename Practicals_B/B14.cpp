/*
The solution to finding the shortest distance from a point to a line segment is defined by the
equation of a line defined through two points P1 (x1, y1) and P2 (x2, y2)

P = P1 + u(P2 − P1)
where
u = (x3 − x1)(x2 − x1) + (y3 − y1)(y2 − y1) / ||P2 − P1||^2

And so, P = (x, y) can be defined as:
x = x1 + u(x2 − x1)     y = y1 + u(y2 − y1)

The distance between the point P3 and the line is the distance between P and P3. Write a
function that computes the distance between a segment and a point. Write a programme
(main function) that demonstrates the use of this distance function, and outputs the results to
screen.
*/

#include <iostream>
#include <math.h>
using namespace std;

template <typename T>
class Point
{
public:
    T x, y;

    Point(T xx, T yy) : x(xx), y(yy){};

    Point<T> subtract(Point<T> &other)
    {
        Point<T> output(x - other.x, y - other.y);
        return output;
    }

    T norm(Point<T> &other)
    {
        return pow((x - other.x), 2) + pow((y - other.y), 2);
    }

    T distance(Point<T> &other)
    {
        return sqrt(pow((x - other.x), 2) + pow((y - other.y), 2));
    }
};

template <typename T>
T calculate_u(Point<T> p1, Point<T> p2, Point<T> p3)
{
    return ((p3.x - p1.x) * (p2.x - p1.x) + (p3.y - p1.y) * (p2.y - p1.y)) / p1.norm(p2);
}

int main()
{
    Point<double> p1(0, 0);
    Point<double> p2(2, 0);
    Point<double> p3(1, 3);
    double u = calculate_u(p1, p2, p3);
    Point<double> p(p1.x + u * (p2.x - p1.x), p1.y + u * (p2.y - p1.y));
    cout << "Point P at (" << p.x << ", " << p.y << ")" << endl;
    double dist = p3.distance(p);
    cout << "Shortest distance is " << dist << endl;
    return 0;
}