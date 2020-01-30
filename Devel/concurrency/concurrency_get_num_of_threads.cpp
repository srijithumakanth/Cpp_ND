#include <iostream>
#include <thread>

int main()
{
    std::cout << "Hello concurrent world from main! Thread ID = " << std::this_thread::get_id() << std::endl;

    return 0;
}