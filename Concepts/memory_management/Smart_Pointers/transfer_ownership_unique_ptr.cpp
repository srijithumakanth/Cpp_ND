#include <iostream>
#include <memory>

class MyClass
{
    private:
        int _member;
    
    public:
        MyClass(int val) : _member{val} {}
        void printVal()
        {
            std::cout << ", managed object " << this << " with val = " << _member << std::endl;
        }
};

void f(std::unique_ptr<MyClass> ptr)
{
    std::cout << "unique_ptr " << &ptr; // Address of the local unique_ptr variable of the function "f" on the stack.
    ptr->printVal(); // Address of the managed object by the unique_ptr variable on the heap.
}

int main()
{
    std::unique_ptr<MyClass> unique_ptr = std::make_unique<MyClass>(23);
    std::cout << "unique_ptr " << &unique_ptr; // Address of the local unique_ptr variable of the function "main" on the stack.
    unique_ptr->printVal(); // Address of the managed object by the unique_ptr variable on the heap.

    f(std::move(unique_ptr)); // Moving the unique_ptr on the main function to the function "f" and transffering all ownership.

    if(unique_ptr) // If the unique_ptr still exists, then print the value else end the program.
    {
        unique_ptr->printVal();
    }

    return (0);
}