#include <iostream>

void myFunction(int &&val)
{
    std::cout << "Value = " << val << std::endl;
}

int main()
{
    myFunction(55); // Pass as rvalue

    int i = 55;
    // myFunction(i); This won't work because an rvalue reference cannot bind to an lvalue reference.
    
    myFunction(std::move(i)); // std::move converts an lvalue into an rvalue. Basically we are stating that in the scope of main,
    // we will not use "i" anymore, it is being moved into the scope of myFunction(). 
    
    return 0;
}