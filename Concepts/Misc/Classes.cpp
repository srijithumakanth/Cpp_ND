#include <iostream>
#include <string>

class BankAccount
{
  private:
      // TODO: declare member variables
        int acc_num_{100};
        std::string acc_name_{""};
        double ava_funds_{100.0};
  public:
      //BankAccount(int num, std::string name, double fund);
      // TODO: declare setters
        void AccNum(int num);
        void AccName(std::string name);
        void AccFunds(double fund);
      // TODO: declare getters
        int AccNum() const;
        std::string AccName() const;
        double AccFunds() const;
};

// Constructor definition
// BankAccount::BankAccount(int num, std::string name, double fund)
// {
//   AccNum(num);
//   AccName(name);
//   AccFunds(fund);
// }
// TODO: implement setters
void BankAccount::AccNum(int num){acc_num_ = num;}
void BankAccount::AccName(std::string name){acc_name_ = name;}
void BankAccount::AccFunds(double fund){ava_funds_ = fund;}
// TODO: implement getters
int BankAccount::AccNum() const {return acc_num_;}
std::string BankAccount::AccName() const {return acc_name_;}
double BankAccount::AccFunds() const {return ava_funds_;}


int main(){
    // TODO: instantiate and output a bank account
    //BankAccount Sam(10510, "Sam Menon", 1000.0);
    BankAccount Sam;
    Sam.AccNum(10510);
    Sam.AccName("Sam Menon");
    Sam.AccFunds(1000.00);
    
    std::cout << "Your account details are: \n";
    std::cout << "Name: " << Sam.AccName() << ", " << "Account Number: " << Sam.AccNum()<< ", " << "Available Funds: $"<< Sam.AccFunds() << "\n";
}