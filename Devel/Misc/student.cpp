#include <cassert>
#include <stdexcept>
#include <string>

// TODO: Define "Student" class
class Student
{
public:
    // Declare constructor
    Student(std::string name, int grade, float gpa);

    // accessors
    std::string Name() const { return name_; }
    int Grade() const { return grade_; }
    float GPA() const { return gpa_; }

    // mutators
    void Name(std::string name) { name_ = name; }
    void Grade(int grade)
    {
        grade_ = grade;
        Validate();
    }
    void GPA(float gpa)
    {
        gpa_ = gpa;
        Validate();
    }

private:
    // name
    std::string name_;

    // grade
    int grade_;

    // GPA
    float gpa_;

    // Validate function
    void Validate()
    {
        if (grade_ < 0 || grade_ > 12)
            throw std::invalid_argument("Invalid Grade Entry");
         else if (gpa_ < 0.0 || gpa_ > 4.0)
             throw std::invalid_argument("Invalid GPA Entry");
    }
};

// Define constructor
Student::Student(std::string name, int grade, float gpa) : name_(name), grade_(grade), gpa_(gpa)
{
    Validate();
}

// TODO: Test
int main()
{
    Student student1("Srijith Menon", 11, 4.0);
    assert(student1.Name() == "Srijith Menon");
    assert(student1.Grade() == 11);
    assert(student1.GPA() == 4.0);

    bool myexception{false};
    try
    {
        Student invalid("Srijith Menon", 0, 5.0);
    }
    catch (...)
    {
        myexception = true;
    }
    assert(myexception);
}