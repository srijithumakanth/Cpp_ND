#include <iostream>
#include <cmath>
#include <assert.h>

// Define pi
#define PI 3.14159;

// Define Line Class
struct LineSegment
{
    public:
        int length = 0;
};
       
// Define Circle subclass
class Circle
{
    public:
        Circle(LineSegment& radius);
        double Area();
    private:
        LineSegment& radius_;
};

    // Define public setRadius() and getArea()
Circle::Circle(LineSegment& radius) : radius_(radius)
{

}

double Circle::Area()
{
    return pow(Circle::radius_.length,2) * PI;
}
// Test in main()
int main() 
{
    LineSegment radius {3};
    Circle circle(radius);
    assert(int(circle.Area()) == 28);
}