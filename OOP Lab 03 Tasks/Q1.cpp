//Samiya Khan
//24K-0768
//Task 01

#include <iostream>
#include <string>
using namespace std;

class Wallet{

private:
    string ownerName;
    double totalBalance;
    string transactionHistory[100];
    int count = 0;

public:
    Wallet(string name, double balance)
    {
        ownerName = name;
        totalBalance = balance;
    }

    void add_money(double amount)
    {
        if (amount > 0)
        {
            totalBalance += amount;
            
            cout << "Amount has been added successfully!!" << endl;
            transactionHistory[count++] = "Added: " + to_string(amount);
        } 
        
        else
        {
            cout << "Amount invalid!!" << endl;
        }
    }

    void spend_money(double amount)
    {
        if (amount > 0 && amount <= totalBalance)
        {
            totalBalance -= amount;
            
            transactionHistory[count++] = "Spent: " + to_string(amount);
            cout << "Amount has been spent successfully!!" << endl;
        } 
        
        else if(amount > totalBalance)
        {
            cout << "Insufficient balance!!" << endl;
        } 
        
        else
        {
            cout << "Amount invalid!!" << endl;
        }
    }

    void display_transaction()
    {
        cout << "Transaction History:" << endl;
        
        if(count == 0)
        {
            cout << "No transactions yet!!" << endl;
        } 
        
        else
        {
            for (int i = 0; i < count; i++)
            {
                cout << transactionHistory[i] << endl;
            }
        } 
    }
};

int main() {
    
    Wallet saad("Saad", 8000.0);
    saad.add_money(5000);
    saad.spend_money(3500);
    saad.display_transaction();

    return 0;
}