#include <iostream>
#include <thread>

void printMessage(std::string message)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); //simulate work
    std::cout << "Thread 1: " << message << std::endl;
}

int main()
{
    // define message
    std::string message = "My Message";

    // start a thread using variadic template
    std::thread t1(printMessage, message);

    // start another thread using a Lamda function
    std::thread t2([message]
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // simulate work
        std::cout << "Thread 2: " << message << std::endl; 
    }
    );

    // thread barriers
    t1.join();
    t2.join();

    return 0;
}