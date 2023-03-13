/*
Part I: Create a base class "Animal" with virtual functions "make_sound()" and
"move()". Create two derived classes "Dog" and "Bird". Override the virtual
functions in the derived classes with appropriate functionality. Create
instances of both the derived classes and call their virtual functions.

Part II: Create a base class "Animal" with pure virtual functions
"make_sound()" and "move()". Create three derived classes "Dog", "Cat", and
"Bird". Override the virtual functions in each of the derived classes with
appropriate functionality. Create a vector of "Animal" pointers that contains
several "Dog" objects, several "Cat" objects, and several "Bird" objects.
Randomly shuffle the vector and then loop through the vector and call the
"make_sound()" and "move()" functions on each object.
*/

#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void make_sound() { cout << "Animal makes sound" << endl; }
    virtual void move() { cout << "Animal moves" << endl; }
};

class Dog : public Animal
{
public:
    void make_sound() { cout << "Woof" << endl; }
    void move() { cout << "Dog runs" << endl; }
};

class Bird : public Animal
{
public:
    void make_sound() { cout << "Chirp" << endl; }
    void move() { cout << "Bird flies" << endl; }
};

int main()
{
    Animal a;
    Dog d;
    Bird b;
    a.make_sound(); // Animal makes sound
    d.make_sound(); // Woof
    b.make_sound(); // Chirp
    return 0;
}