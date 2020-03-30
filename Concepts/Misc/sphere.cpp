#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>

// TODO: Define class Sphere
class Sphere
{
public:
    // Constructor
    Sphere(int radius) : radius_(radius), volume_(pi_ * 4 / 3 * pow(radius_, 3))
    {
        if (radius <= 0)
            throw std::invalid_argument("radius must be positive");
    }

    // Accessors
    int Radius() const { return radius_; }
    int Volume() const { return volume_; }

    // Mutator
    void Radius(int radius)
    {   
        if (radius <= 0)
            throw std::invalid_argument("radius must be positive");
        radius_ = radius;
        volume_ = pi_ * 4 / 3 * pow(radius_, 3);
    }

private:
    // Private members
    //static float constexpr pi_{3.14159};
    static float const pi_;
    int radius_;
    float volume_;
};

float const Sphere::pi_{3.14159};
// Test
int main(void)
{
    Sphere sphere(5);
    assert(sphere.Radius() == 5);
    assert(abs(sphere.Volume() - 523.6) < 1);

    sphere.Radius(3);
    assert(sphere.Radius() == 3);
    //std::cout<<"Voume is: " << abs(sphere.Volume()) << "\n";
    assert(abs(sphere.Volume() - 113.01) < 1);

    bool caught{false};
    try
    {
        sphere.Radius(-1);
    }
    catch (...)
    {
        caught = true;
    }
    assert(caught);
}
