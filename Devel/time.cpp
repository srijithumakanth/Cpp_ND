#include <ctime>
#include <iostream>

class Date {
public:
    Date(int day, int month, int year) : day_(day), month_(month), year_(year) {}
    Date(int day, int month) : day_(day), month_(month)  // automatically sets the Date to the current year
    {
        time_t t = time(NULL);
        tm* timePtr = localtime(&t);
        year_ = timePtr->tm_year;
    }

    int Day() const { return day_; }
    int Month() const { return month_; }
    int Year() const { return year_; }

private:
    int day_;
    int month_;
    int year_;
};

int main()
{
    //Date date(10, 10, 1010);
    Date date(10, 10);
    //date.Date(date.Day(), date.Month());
    std::cout << "Today's date is (dd/mm/yyyy): " << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
}