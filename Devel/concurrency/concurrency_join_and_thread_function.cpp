#include <iostream>
#include <thread>

void threadFunction()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // to simulate some work done in the function
    std::cout << "Finished work in the thread\n";
}

int main()
{
    // Create thread
    std::thread th(threadFunction);

    // Do something in main()
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate some work
    std::cout << "Finished work in main thread\n";

    // Wait for the other thread in the thread function to finish
    th.join();

    return 0;
}