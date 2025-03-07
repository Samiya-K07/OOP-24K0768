//Samiya Khan
//24K-0768

#include<iostream>
#include<string>
using namespace std;

class Account{
protected:
    int accountNumber;
    float balance;

public:
    Account(int new_an, float new_balance) : accountNumber(new_an), balance(new_balance) {}

    void displayDetails() 
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount:public Account{
private:
    float interestRate;

public:
    SavingsAccount(int new_an, float new_balance, float new_rate) : Account(new_an, new_balance), interestRate(new_rate) {}

    void displayDetails() 
    {
        Account::displayDetails();
        cout << "Interest Rate: " << interestRate << endl;
    }
};

class CheckingAccount:public Account{
private:
    float overdraftLimit;

public:
    CheckingAccount(int new_an, float new_balance, float new_limit) : Account(new_an, new_balance), overdraftLimit(new_limit) {}

    void displayDetails() 
    {
        Account::displayDetails();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {

    SavingsAccount s1(1356, 8000.0, 6);

    CheckingAccount c1(1356, 6000.0, 2);

    cout << "Savings Account Details:" << endl;
    s1.displayDetails();
    
    cout << "Checking Account Details:" << endl;
    c1.displayDetails();

    return 0;
}