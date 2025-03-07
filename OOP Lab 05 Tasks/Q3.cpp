//Samiya Khan
//24K-0768

#include<iostream>
#include<string>
using namespace std;

class Employee{
public:
    string name;
    string designation;

    Employee(string n, string d) : name(n), designation(d) {}

    void displayDetails() 
    {
        cout << "Employee Name: " << name << "\nDesignation: " << designation << endl;
    }
};

class Project{
public:
    string title;
    string deadline;
    Employee* employees[10];
    int employeeCount = 0;

    Project(string t, string d) : title(t), deadline(d) {}

    void addEmployee(Employee* e) 
    {
        if (employeeCount < 10) 
        {
            employees[employeeCount++] = e;
        } 
        
        else 
        {
            cout << "Limit reached!! Cannot add more employees!!" << endl;
        }
    }

    void displayDetails() 
    {
        cout << "Project Title: " << title << "\nDeadline: " << deadline << "\nAssigned Employees: " << endl;
        
        if (employeeCount == 0) 
        {
            cout << "No employees assigned yet!!";
        } 
        
        else 
        {
            for (int i = 0; i < employeeCount; i++)
            {
                employees[i]->displayDetails();
            }
        }
        cout << endl;
    }
};

int main() {
    Employee employee1("Abeer Fatima", "Employee/Worker");
    Employee employee2("Samiya Khan", "Manager");
    Employee employee3("Umna Syed", "Executive");

    Project project1("Project Launch", "3-7-2025");
    Project project2("Warehouse Development", "4-10-2025");

    project1.addEmployee(&employee1);
    project1.addEmployee(&employee2);
    project2.addEmployee(&employee2);
    project2.addEmployee(&employee3);

    cout << "Project 01 Details:" << endl;
    project1.displayDetails();

    cout << "Project 02 Details:" << endl;
    project2.displayDetails();

    return 0;
}