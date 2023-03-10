#include <iostream>
#include <cmath>

class Point
{
public:
    Point(int xx, int yy);

    void setX(int xx);
    void setY(int yy);
    int getX();
    int getY();
    float distance(Point p);

private:
    int x, y;
};

Point::Point(int xx, int yy)
    : x(xx), y(yy){};
// Point::Point(int xx, int yy)
// {
//     x = xx;
//     y = yy;
// }

void Point::setX(int xx) { x = xx; }
void Point::setY(int yy) { y = yy; }
int Point::getX() { return x; }
int Point::getY() { return y; }
float Point::distance(Point p)
{
    return sqrt(pow((x - p.getX()), 2) + pow((y - p.getY()), 2));
}

int main()
{
    Point p(1, 2);
    std::cout << p.getX() << std::endl;
    std::cout << p.getY() << std::endl;
    p.setX(3);
    p.setY(4);
    std::cout << p.getX() << std::endl;
    std::cout << p.getY() << std::endl;

    Point p2(1, 2);
    std::cout << "distance: " << p.distance(p2) << std::endl;
    return 0;
}