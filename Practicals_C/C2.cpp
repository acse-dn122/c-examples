/*
Write your own version of the std::shared_ptr<T> templated smart pointer, called myShrdPtr
(note you cannot use the std::shared_ptr<T> in your implementation). This should be a
templated class, where you are required to implement a constructor that takes a raw pointer
as input and takes ownership of that memory.

You should also implement a copy constructor that takes an existing myShrdPtr and copies
it. The myShrdPtr should keep track of how many other myShrdPtr’s point at the same object
they own. You must include a destructor that deletes the memory owned by the myShrdPtr
when there are no other myShrdPtr pointing at the same object. You must also overload the
dereferencing operator, *, which returns the object myShrdPtr is pointing at by reference.

How would you change the implementation of myShrdPtr if this class were trying to
implement std::weak_ptr? Write a few sentences describing your proposed changes (note
you don’t have to make any changes or write extra code; be specific about your proposed
changes, for example, would your dereferencing operator change?) in a document and
modify the source files of myShrdPtr. You should also create a cpp file containing a main
method that builds a new instance of myShrdPtr.
*/

#include <iostream>
using namespace std;

// A generic smart pointer class
template <class T>
class myShrdPtr
{
    T *ptr; // Actual pointer
    int *count = new int;

public:
    // Constructor
    explicit myShrdPtr(T *p = NULL)
    {
        ptr = p;
        *count = 1;
    }

    explicit myShrdPtr(myShrdPtr<T> &p)
    {
        ptr = p.ptr;
        count = p.count;
        ++(*count);
    }

    // explicit myShrdPtr(){};

    // Destructor
    ~myShrdPtr()
    {
        --(*count);
        if (*count == 0)
        {
            delete ptr;
            delete count;
        }
    }

    int use_count()
    {
        return *count;
    }

    // Get the pointer
    T *get()
    {
        return ptr;
    }

    // Overloading dereferencing operator
    T &operator*() { return *ptr; }

    // Overloading arrow operator so that members of T can be accessed like a pointer
    T *operator->() { return ptr; }

    friend ostream &operator<<(ostream &os, myShrdPtr<T> &sp)
    {
        os << "Counter:" << sp.use_count() << endl;
        os << "Address pointed : " << sp.get() << endl;
        return os;
    }
};

int main()
{
    cout << "--- Shared pointers ptr1 ---\n";
    myShrdPtr<int> ptr1(new int());
    *ptr1 = 20;
    cout << ptr1;

    cout << "\n--- Shared pointers ptr1, ptr2 ---\n";
    myShrdPtr<int> ptr2(ptr1);
    *ptr2 = 10;
    cout << ptr1;
    cout << ptr2;

    {
        cout << "\n--- Shared pointers ptr1, ptr2, ptr3 ---\n";
        myShrdPtr<int> ptr3(ptr1);
        *ptr1 = 50;
        cout << ptr1;
        cout << ptr2;
        cout << ptr3;

        cout << "\nCounter before destroy: " << ptr1.use_count() << endl;
    }

    cout << "Counter after destroy: " << ptr1.use_count() << endl;

    cout << "\n--- Shared pointers ptr1, ptr2 ---\n";
    cout << ptr1;
    cout << ptr2;
    
    return 0;
}

// g++ -std=c++11 C2.cpp ../assessment_matrix/CSRMatrix.cpp ../assessment_matrix/Matrix.cpp -o C2