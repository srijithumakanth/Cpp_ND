#include <iostream>
#include <memory>

class MyClass
{
public:
    std::shared_ptr<MyClass> _member;
    ~MyClass() { std::cout << "Destructor of MyClass called" << std::endl; }
};

int main()
{
    std::shared_ptr<MyClass> myClass1(new MyClass);
    std::shared_ptr<MyClass> myClass2(new MyClass);

    /* The assignment below causes circular reference and leads to memory leaks (verify using valgrind)
    myClass1->_member = myClass2;
    myClass2->_member = myClass1;
    */

    return 0;
}