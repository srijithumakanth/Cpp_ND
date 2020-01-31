/* QUESTION:  What is wrong with this program? */

#include <iostream>

// RAII memory management class
class MyInt
{
  public:
    MyInt (int *p = NULL) 
    {
        _p = p;
    }

    ~MyInt()
    {
        std::cout << "Resource " << *_p << " deallocated" << std::endl;
        delete _p;
    }

    int &operator*() // overloading dereferencing operator
    {
        return *_p;
    }

  private:
    int *_p; // pointer to the heap data

}; 

int main()
{
    double den[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    for (size_t i = 0; i < 5; ++i)
    {
        // allocate resource on the stack
        MyInt *en = new MyInt(new int(i));

        // use the resource
        std::cout << **en << "/" << den[i] << " = " << **en / den[i] << std::endl;
    }
    return 0;
}

/* Answer: The program will compile fine and run without any problems, 
but it is actually causing a memory leak because the destructor of MyInt RAII memory management class 
is not being called hence the memory on the heap is not properly deallocated*/