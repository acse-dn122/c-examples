/* Create a base class called Furniture with derived classes Chair, Table, and Sofa. Implement
a virtual function price() in each derived class that calculates the price of the furniture based
on its material and size. Store the material and sizes, and use them in your calculations. */

#include <iostream>
using namespace std;

class Furniture
{
public:
    virtual double price() = 0;
    virtual ~Furniture(){};
};

class Chair : public Furniture
{
public:
    Chair(double material, double size)
        : material{material}, size{size} {}
    virtual double price()
    {
        return material * size;
    }

private:
    double material;
    double size;
};

class Table : public Furniture
{
public:
    Table(double material, double size)
        : material{material}, size{size} {}
    virtual double price()
    {
        return material * size;
    }

private:
    double material;
    double size;
};

class Sofa : public Furniture
{
public:
    Sofa(double material, double size)
        : material{material}, size{size} {}
    virtual double price()
    {
        return material * size;
    }

private:
    double material;
    double size;
};

int main()
{
    Furniture *furniture1 = new Chair(20, 2);
    cout << "The price of the chair is $" << furniture1->price() << endl;

    Furniture *furniture2 = new Table(30, 3);
    cout << "The price of the table is $" << furniture2->price() << endl;

    Furniture *furniture3 = new Sofa(40, 4);
    cout << "The price of the sofa is $" << furniture3->price() << endl;

    delete furniture1;
    delete furniture2;
    delete furniture3;
    return 0;
}