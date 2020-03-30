#include <iostream>
#include <thread>

void threadFunction()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work in thread\n";
}

int main()
{
    // Create thread
    std::thread th(threadFunction);

    // Detach thread and continue with main()
    th.detach();

    // Simulate work in the main()
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work in main\n";

    return 0;
}