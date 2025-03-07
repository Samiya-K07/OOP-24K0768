//Samiya Khan
//24K-0768

#include<iostream>
#include<string>
using namespace std;

class Employee{
protected:
    string name;
    float salary;

public: 
    Employee(string new_name, float new_salary) 
    {
        name = new_name;
        salary = new_salary;
    }

    void displayDetails() 
    {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Manager:public Employee{
private:
    float bonus;

public:
    Manager(string new_name, float new_salary, float new_bonus) : Employee(new_name, new_salary) 
    {
        bonus = new_bonus;
    }

    void displayDetails() 
    {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Bonus: " << bonus << endl;
    }
};

int main() {

    Manager manager1("Samiya", 6500.0, 550.0);

    cout << "Manager Details: " << endl;
    manager1.displayDetails();

    return 0;
}