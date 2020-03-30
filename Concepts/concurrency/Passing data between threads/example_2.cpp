/* Promises and furtures for passing data (one-time) from  a worker thread to the main thread.*/

#include <iostream>
#include <thread>
#include <future>

void modifyMessage(std::string message, std::promise<std::string> && promise)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(4000)); //simulate work
    std::string modifiedMessage = message + " has been succesfully modified.";
    promise.set_value(modifiedMessage);
}

int main()
{
    // define message
    std::string message = "My Message";

    // create promise and future
    std::promise<std::string> promise;
    std::future<std::string> future = promise.get_future();

    // start a thread using variadic template and pass promise as an argument
    std::thread t1(modifyMessage, message, std::move(promise));
    
    // print out original message to the console
    std::cout << "Original message from main():  " << message << std::endl;

    // retrieve modified message from the thread and print it out to the console
    std::string messageFromThread = future.get();
    std::cout << "Modified message from the thread(): " << messageFromThread << std::endl;
    
    // thread barriers
    t1.join();

    return 0;
}