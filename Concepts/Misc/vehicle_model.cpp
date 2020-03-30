#include <assert.h>
#include <cmath>

// TODO: Define PI
#define PI 3.14159

// TODO: Declare abstract class VehicleModel
class VehicleModel
{
    // TODO: Declare virtual function Move()
public:
    virtual void Move(double v, double phi) = 0;
};

// TODO: Derive class ParticleModel from VehicleMode
class ParticleModel : public VehicleModel
{
    // TODO: Override the Move() function
public:
      // TODO: Define x, y, and theta
    double x = 0;
    double y = 0;
    double theta = 0;

    void Move(double v, double phi) override
    {
        theta += phi;
        x += v * cos(theta);
        y += v* sin(theta);
    }
  
};

// TODO: Derive class BicycleModel from ParticleModel
class BicycleModel : public ParticleModel
{
    // TODO: Override the Move() function
public:
    // TODO: Define L
    double L = 1;

    void Move(double v, double phi) override
    {
        theta += v / L * tan(phi);
        x += v * cos(theta);
        y += v* sin(theta);
    }
  
};


// TODO: Pass the tests
int main()
{
    // Test function overriding
    ParticleModel particle;
    BicycleModel bicycle;
    particle.Move(10, PI / 9);
    bicycle.Move(10, PI / 9);
    assert(particle.x != bicycle.x);
    assert(particle.y != bicycle.y);
    assert(particle.theta != bicycle.theta);
}