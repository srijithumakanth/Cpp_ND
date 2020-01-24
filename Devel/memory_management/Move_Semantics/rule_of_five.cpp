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

    MyMovableClass (MyMovableClass &&source) // 4: Move constructor. An rvalue reference to source object of same class 
                                             // is taken as input argument
    {
        std::cout << "MOVING (c’tor) instance " << &source << " to instance " << this << std::endl;
        _data = source._data;
        _size = source._size;
        
        source._data = nullptr;
        source._size = 0;
    }

    MyMovableClass &operator=(MyMovableClass &&source) // 5: Move assignment operator
    {
        std::cout << "MOVING (assign) instance " << &source << " to instance " << this << std::endl;
        if (this == &source)
            return *this;
        
        delete[] _data;
        
        _data = source._data;
        _size = source._size;

        source._data = nullptr;
        source._size = 0;

        return *this;
    }
};

void useObject(MyMovableClass obj)
{
    std::cout << "using object " << &obj << std::endl;
}

// int main() // Rule of three
// {
//     MyMovableClass obj1(10); // regular constructor

//     MyMovableClass obj2(obj1); // copy constructor

//     obj2 = obj1; // copy assignment operator

//     obj1 = obj1; // self-assignment --> PROHIBITED but protected against in copy assignment operator
// }

int main() // Rule of five
{
    MyMovableClass obj1(100); // regular constructor

    // useObject(obj1); // This method invokes the copy constructor as we as passing it as lvalue

    useObject(std::move(obj1)); // std::move converts a lvalue to a rvalue thus invoking the move constructor 
                               //  and making the compiler do a move semantics rather than
                               // copy semantics as seen in the previous usage of this function. obj1 goes 
                               // out of scope in the main function. You could theoretically access it but it will be a real bad idea.

    // obj1 = MyMovableClass(200); // move assignment operator. A second instance of MyMovableClass 
                                // is created as an rvalue, which is assigned to obj1. 

    // MyMovableClass obj2 = MyMovableClass(300); // move constructor. A second lvalue obj2, 
                                               // which is created by assigning it an rvalue object.
    
    

    return 0;
}
