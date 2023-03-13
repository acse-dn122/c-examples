/*
Part II: Create a base class "Animal" with pure virtual functions
"make_sound()" and "move()". Create three derived classes "Dog", "Cat", and
"Bird". Override the virtual functions in each of the derived classes with
appropriate functionality. Create a vector of "Animal" pointers that contains
several "Dog" objects, several "Cat" objects, and several "Bird" objects.
Randomly shuffle the vector and then loop through the vector and call the
"make_sound()" and "move()" functions on each object.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

class Animal
{
public:
    virtual void make_sound() = 0;
    virtual void move() = 0;
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
    Dog d;
    Bird b;
    d.make_sound();
    b.make_sound();

    std::cout << "----- Using pointers below -----\n";

    vector<Animal *> animals;
    const int num_dogs = 3;
    const int num_birds = 4;

    for (int i = 0; i < num_dogs; ++i) {
        animals.push_back(new Dog);
    }

    for (int i = 0; i < num_birds; ++i) {
        animals.push_back(new Bird);
    }

    // random_shuffle(animals.begin(), animals.end());

    unsigned seed = 0; // To obtain a time-based seed
  
    shuffle(animals.begin(), animals.end(), default_random_engine(seed));

    for (Animal *&animal : animals)
    {
        animal->make_sound();
    }
}