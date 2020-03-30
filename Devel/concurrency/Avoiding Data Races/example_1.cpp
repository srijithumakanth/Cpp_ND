/* One of the primary sources of error in concurrent programming are data races. 
They occur, when two concurrent threads are accessing the same memory location while at least one of them 
is modifying (the other thread might be reading or modifying). In this scenario, the value at the memory 
location is completely undefined. Depending on the system scheduler, the second thread will be executed 
at an unknown point in time and thus see different data at the memory location with each execution. 
Depending on the type of program, the result might be anything from a crash to a security breach when 
data is read by a thread that was not meant to be read, such as a user password or other sensitive information.
 Such an error is called a „data race“ because two threads are racing to get access to a memory location first,
  with the content at the memory location depending on the result of the race. */

#include <iostream>
#include <thread>
#include <future>

class Vehicle
{
public:
    //default constructor
    Vehicle() : _id(0)
    {
        std::cout << "Vehicle #" << _id << " Default constructor called" << std::endl;
    }

    //initializing constructor
    Vehicle(int id) : _id(id)
    {
        std::cout << "Vehicle #" << _id << " Initializing constructor called" << std::endl;
    }

    // setter and getter
    void setID(int id) { _id = id; }
    int getID() { return _id; }

private:
    int _id;
};

int main()
{
    // create instances of class Vehicle
    Vehicle v0; // default constructor
    Vehicle v1(1); // initializing constructor

    // read and write name in different threads (which one of the above creates a data race?)
    std::future<void> ftr = std::async([](Vehicle v) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // simulate work
        v.setID(2);
    }, v0);

    v0.setID(3);

    ftr.wait();
    std::cout << "Vehicle #" << v0.getID() << std::endl;

    return 0;
}