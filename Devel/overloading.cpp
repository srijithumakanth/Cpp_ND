#include <iostream>

class Human {};
class Dog {};
class Cat {};

// TODO: Write hello() function
void Hello()
{
    std::cout << "Hello World!! \n";
}

// TODO: Overload hello() three times
void Hello(Human human)
{
    std::cout << "Hello World!! \n";
}

void Hello(Dog dog)
{
    std::cout << "Bow Bow World!! \n";
}

void Hello(Cat cat)
{
    std::cout << "Meow Meow World!! \n";
}

// TODO: Call hello() from main()
int main()
{
    //Hello();
    Hello(Human());
    Hello(Dog());
    Hello(Cat());
}