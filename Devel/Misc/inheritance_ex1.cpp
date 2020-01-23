#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
    int wheels = 0;
    string color = "blue";
    string make  = "generic";
    void Print() const
    {
        std::cout << "This " << color << " " << make << " vehicle has " << wheels << " wheels!" << " with ID " << ID_ << "\n";
    }
    int ID()
    { 
        Print(); 
        return ID_;
    }
private:
    int ID_ = 0;
    
};

class Car : public Vehicle {
public:
    bool sunroof = false;
};

class Bicycle : private Vehicle {
public:
    bool kickstand = true;
};

class Scooter : private Vehicle {
public:
    bool electric = false;
    void Wheels(int w)
    {
        wheels = w;
    }
    void PrintScoot()
    {
        Print();
    }
 
};

class ScootID : public Vehicle
{

};

int main() 
{
    // Scooter scooter;
    // scooter.Wheels(2);
    // scooter.PrintScoot();

    ScootID s;
    s.ID();
};