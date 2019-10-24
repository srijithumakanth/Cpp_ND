#include <cassert>
#include <stdexcept>

// TODO: Define class Pyramid
class Pyramid
{
    // public class members
public:
    // Declare constructor
    Pyramid(int length, int width, int height);

    // accessors
    int Length() const { return length_; }
    int Width() const { return width_; }
    int Height() const { return height_; }

    // mutators
    void Length(int l)
    {
        length_ = l;
        ValidateDim();
    }
    void Width(int w)
    {
        width_ = w;
        ValidateDim();
    }
    void Height(int h)
    {
        height_ = h;
        ValidateDim();
    }

    // public Volume() function
    float Volume()
    {
        return (Length() * Width() * Height()) / 3.0;
    }

    // private class members
private:
    int length_;
    int width_;
    int height_;
    void ValidateDim()
    {
        if (length_ <= 0 || width_ <= 0 || height_ <= 0)
            throw std::invalid_argument("Negative Dimension provided.");
    }
};

// Define constructor
Pyramid::Pyramid(int length, int width, int height) : length_(length), width_(width), height_(height)
{
    ValidateDim();
}
// Test
int main()
{
    Pyramid pyramid(4, 5, 6);
    assert(pyramid.Length() == 4);
    assert(pyramid.Width() == 5);
    assert(pyramid.Height() == 6);
    assert(pyramid.Volume() == 40);

    bool caught{false};
    try
    {
        Pyramid invalid(-1, 2, 3);
    }
    catch (...)
    {
        caught = true;
    }
    assert(caught);
}