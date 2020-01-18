/* Comments:
Throughout the program, the address of the managed object does not change. When passed to f() , 
the reference count changes to 2. After the function returns and the local shared_ptr is destroyed, 
the reference count changes back to 1. In summary, move semantics are usually not needed when using shared pointers. 
Shared pointers can be passed by value safely and the main thing to remember is that with each pass, 
the internal reference counter is increased while the managed object stays the same.

Without giving an example here, the weak_ptr can be passed by value as well, just like the shared pointer. 
*/

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


void f(std::shared_ptr<MyClass> ptr)
{
    std::cout << "shared_ptr (ref_cnt= " << ptr.use_count() << ") " << &ptr;
    ptr->printVal();
}

int main()
{
    std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>(23);
    std::cout << "shared_ptr (ref_cnt= " << sharedPtr.use_count() << ") " << &sharedPtr;
    sharedPtr->printVal();

    f(sharedPtr);

    std::cout << "shared_ptr (ref_cnt= " << sharedPtr.use_count() << ") " << &sharedPtr;
    sharedPtr->printVal();

    return 0;
}