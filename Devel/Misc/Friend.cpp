// Example solution for Rectangle and Square friend classes
#include <assert.h>
#include<iostream>

// Declare a class Rectangle
class Rectangle;

// Define class Square as friend of Rectangle
class Square
{
    // Add public constructor to Square, initialize side
    public:
    Square(int side) : side_(side){};
    // Add friend class Rectangle
    friend class Rectangle;

    // Add private attribute side
    private:
    int side_;
};


// Define class Rectangle
class Rectangle
{
    // Add public function to Rectangle: Area()
    public:
        Rectangle(const Square& square);
        double Area() const;
    
    // Add private attributes width, height;
    private:
        int width_;
        int height_;

};
    
// Define a Rectangle constructor that takes a Square
Rectangle::Rectangle(const Square& square)
{
    if (square.side_ <= 0)
    {
       throw std::invalid_argument("Side cannot be negative or zero.");
    }
    width_ = square.side_;
    height_ = square.side_;
};

// Define Area() to compute area of Rectangle
double Rectangle::Area() const
{
        return width_* height_;
}

// Update main() to pass the tests
int main()
{
    Square square(4);
    Rectangle rectangle(square);
    assert(rectangle.Area() == 16); 
}