#include <iostream>
using namespace std;

class base
{
public:
    virtual void vprint() const { cout << "base" << endl; } // virtual !
    void print() const { cout << "base" << endl; }
};

class sub : public base
{
public:
    void vprint() const { cout << "sub" << endl; }
    void print() const { cout << "sub" << endl; }
};

class subsub : public sub
{
public:
    void vprint() const { cout << "subsub" << endl; }
    void print() const { cout << "subsub" << endl; }
};

int main()
{
    base b;
    sub s;
    subsub ss;
    b.print();
    s.print();
    ss.print(); // "base", "sub", "subsub"
    std::cout << "\n";
    b.vprint();
    s.vprint();
    ss.vprint(); // "base", "sub", "subsub"
    std::cout << "\n";

    std::cout << "----- Using pointers below -----\n";

    base *p[3]; // pointers to base class
    p[0] = &b;
    p[1] = &s;
    p[2] = &ss;
    for (int i = 0; i < 3; i++)
        p[i]->print(); // "base", "base", "base"
    std::cout << "\n";
    for (int i = 0; i < 3; i++)
        p[i]->vprint(); // "base", "sub", "subsub"

    return 0;
}