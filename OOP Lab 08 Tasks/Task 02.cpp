#include<iostream>
using namespace std;

class Account{
private:
    int accountNumber;
    double balance;

public:
    Account(int account, double bal) : accountNumber(account), balance(bal) {}

    friend class Manager;

    friend void transferFunds(Account& from, Account& to, double amount);
};

class Manager{
public:
    void display(const Account& account) 
    {
        cout << "Account Number: " << account.accountNumber << endl;
        cout <<  "Balance: " << account.balance << endl;
    }

    void deposit(Account& account, double amount) 
    {
        if (amount > 0) 
        {
            account.balance += amount;
            cout << "$" << amount << " successfully deposited to account " << account.accountNumber << endl;
            cout << "New Balance: " << account.balance << endl;
        } 
        
        else 
        {
            cout << "Invalid Amount!!" << endl;
        }
    }

    void withdraw(Account& account, double amount) 
    {
        if (amount > 0 && account.balance >= amount) 
        {
            account.balance -= amount;
            cout << "$" << amount << " withdrawn from account " << account.accountNumber << endl;
            cout << "New Balance: " << account.balance << endl;
        } 
        
        else 
        {
            cout << "Either invalid amount or insufficient balance!!" << endl;
        }
    }
};

void transferFunds(Account& from, Account& to, double amount) 
{
    if (amount > 0 && from.balance >= amount) 
    {
        from.balance -= amount;
        to.balance += amount;
        cout << "$" << amount << " transferred from account " << from.accountNumber << " to account " << to.accountNumber << endl;
    } 
    
    else 
    {
        cout << "Transfer unsuccessful. due to either invalid amount or insufficient balance in account: " << from.accountNumber << endl;
    }
}

int main(){
    
    Account a1(101, 10000);
    Account a2(102, 20000);
    Manager m1;

    m1.display(a1);
    m1.display(a2);

    m1.deposit(a1, 1000);
    m1.withdraw(a2, 6000);

    transferFunds(a1, a2, 2000);

    m1.display(a1);
    m1.display(a2);

    return 0;
}