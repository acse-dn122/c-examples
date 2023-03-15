/*
Consider a tetrahedron defined by four nodes a, b, c, d.
The volume of a tetrahedron with vertices a = (ax, ay, az), b = (bx, by, bz), c = (cx, cy, cz), and d = (dx, dy, dz), can be computed by solving this equation:
Equation C.1:

Now consider an irregular hexahedron defined by eight nodes h0, h1, h2, h3, h4, h5, h6, h7.
The volume of an irregular hexahedron can be computed by adding the volume of subtetrahedra formed by vertices (h0,h1,h3,h4), (h4,h1,h3,h5), (h4,h5,h3,h7),
(h1,h2,h3,h6), (h3,h1,h6,h5), (h5,h6,h3,h7).

Part 1: Write a function VolumeOfTetra that computes the volume of a tetrahedron using
Equation C.1.

Part 2: Write a function VolumeOfHexa that computes the volume of a hexahedron by adding
the volume of sub-tetrahedra that compose it.

Part 3: Write a main function that creates 1,000 random hexahedra and compute their
volumes. Display the sum of the volumes of the computed hexahedra to screen. Note:
ensure that your programme creates hexahedra that have eight distinct nodes.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

template <typename T>
class Point
{
public:
    T x;
    T y;
    T z;

    Point(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {};
    Point(){};

    ~Point(){};

    Point<T> subtract(Point<T> p)
    {
        Point<T> output(x - p.x, y - p.x, z - p.x);
        return output;
    }

    T dot(Point<T> p)
    {
        return x * p.x + y * p.y + z * p.z;
    }

    Point<T> cross(Point<T> p)
    {
        T x1 = y * p.z - z * p.y;
        T y1 = z * p.x - x * p.z;
        T z1 = x * p.y - y * p.x;
        Point<T> output(x1, y1, z1);
        return output;
    }
};

template <typename T>
T VolumeOfTetra(Point<T> a, Point<T> b, Point<T> c, Point<T> d)
{
    Point<T> a_d = a.subtract(d);
    Point<T> b_d = b.subtract(d);
    Point<T> c_d = c.subtract(d);

    T volume = abs(a_d.dot(b_d.cross(c_d))) / 6;

    return volume;
}

template <typename T>
T VolumeOfHexa(Point<T> h0, Point<T> h1, Point<T> h2, Point<T> h3, Point<T> h4, Point<T> h5, Point<T> h6, Point<T> h7)
{
    T volume_1 = VolumeOfTetra(h0, h1, h3, h4);
    T volume_2 = VolumeOfTetra(h4, h1, h3, h5);
    T volume_3 = VolumeOfTetra(h4, h5, h3, h7);
    T volume_4 = VolumeOfTetra(h1, h2, h3, h6);
    T volume_5 = VolumeOfTetra(h3, h1, h6, h5);
    T volume_6 = VolumeOfTetra(h5, h6, h3, h7);

    return volume_1 + volume_2 + volume_3 + volume_4 + volume_5 + volume_6;
}

int main()
{
    unordered_set<double> hexa;
    vector<double> hexa_vecotr(8 * 3);
    while (hexa.size() < 8 * 3)
    {
        double p = rand() % 100;
        hexa.insert(p);
    }

    std::copy(hexa.begin(), hexa.end(), hexa_vecotr.begin()); // copy to a vector for access

    vector<Point<double>> hexa_v(8); // generate collection of points

    for (int i = 0; i < 8; i++)
    {
        Point<double> point(hexa_vecotr[i * 3], hexa_vecotr[i * 3 + 1], hexa_vecotr[i * 3 + 2]);
        hexa_v[i] = point;
    }
    double volume = VolumeOfHexa(hexa_v[0], hexa_v[1], hexa_v[2], hexa_v[3], hexa_v[4], hexa_v[5], hexa_v[6], hexa_v[7]);
    cout << volume << endl;
    return 0;
}