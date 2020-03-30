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
        // allocate the resource on the heap
        //double *en = new double(i); // standard method
        
        // allocate resource on the stack
        // MyInt en(new int(i));  // RAII method (less error prone)
        MyInt *en = new MyInt(new int(i)); // if done in this fashion, the destructor of MyInt is never called, thus causing memory leak.

        // use the resource
        std::cout << *en << "/" << den[i] << " = " << *en / den[i] << std::endl;

        // deallocate the resource 
        //delete en; // standard method
    }
    return 0;
}