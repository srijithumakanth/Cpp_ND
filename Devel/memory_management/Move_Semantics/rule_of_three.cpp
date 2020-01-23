#include <stdlib.h>
#include <iostream>

class MyMovableClass
{
private:
    int _size;
    int *_data;

public:
    MyMovableClass(size_t size) // Constructor
    {
        _size = size;
        _data = new int[_size];
        std::cout << "CREATING instance of MyMovableClass at " << this << " allocated with size = " << _size*sizeof(int)  << " bytes" << std::endl;
    }

    ~MyMovableClass() // 1: Destructor
    {
        std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
        delete[] _data;
    }

    MyMovableClass (const MyMovableClass &source)  // 2: Copy constructor // const is used to make sure these constructors 
                                                   // won't and cant modify the content of source
    {
        _size = source._size;
        _data = new int[_size];
        *_data = *source._data;
        std::cout << "COPYING content of instance " << &source << " to instance " << this << std::endl;
    }

    MyMovableClass &operator=(const MyMovableClass &source) // 3: Copy assignment operator
    {
        std::cout << "ASSIGNING content of instance " << &source << " to instance " << this << std::endl;
        if (this == &source) // The if statement protects against self-assignment and is a standard boilerplate code 
                             // user-defined assignment operator.
            return *this;
        
        delete[] _data;
        _data = new int[source._size];
        _size = source._size;
        return *this;
    }
};

int main()
{
    MyMovableClass obj1(10); // regular constructor

    MyMovableClass obj2(obj1); // copy constructor

    obj2 = obj1; // copy assignment operator

    obj1 = obj1; // self-assignment --> PROHIBITED but protected against in copy assignment operator
}