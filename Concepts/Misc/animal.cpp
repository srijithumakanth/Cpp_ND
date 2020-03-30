#include <iostream>
#include <string>
using std::string;

// Define base class Animal
class Animal
{
private:
    /* data */
public:
    string color = " ";
    string name = " ";
    int age = 0;     
};

// Declare derived class Snake
class Snake : public Animal
{
    public:
        int length = 0;
        string MakeSound()
        {
            return "SSsssssss!!!!! \n";
        }

};
// Declare derived class Cat
class Cat : public Animal
{
    public:
        int height = 0;
        string MakeSound()
        {
            return "Meoowwwww!!!!! \n";
        }

};
// Test in main()

int main()
{
    Snake snake;
    snake.color = "Brown";
    snake.name = "Jeremy";
    snake.age = 7;
    snake.length = 5;

    std::cout << "Snake: \n" << "Name: " << snake.name << "; \n" << " Color: " << snake.color << ";\n" << " Age: " << snake.age << ";\n" << " Sound: " << snake.MakeSound();

    Cat cat;
    cat.color = "White";
    cat.name = "Bob";
    cat.age = 5;
    cat.height = 2;

    std::cout << "Cat: \n" << "Name: " << cat.name << "; \n" << " Color: " << cat.color << ";\n" << " Age: " << cat.age << ";\n" << " Sound: " << cat.MakeSound();

}