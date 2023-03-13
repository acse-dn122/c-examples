/* Create a base class called Furniture with derived classes Chair, Table, and Sofa. Implement
a virtual function price() in each derived class that calculates the price of the furniture based
on its material and size. Store the material and sizes, and use them in your calculations. */

class Furniture
{
public:
    virtual double price() = 0;
};

class Chair : public Furniture
{
public:
    Chair(double material, double size)
        : material{material}, size{size} {}
    double price()
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
    double price()
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
    double price()
    {
        return material * size;
    }

private:
    double material;
    double size;
};

int main()
{
    return 0;
}