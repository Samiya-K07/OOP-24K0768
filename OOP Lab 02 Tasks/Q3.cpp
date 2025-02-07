//Samiya Khan
//24K-0768
//Task 03

#include <iostream>
#include <string>
using namespace std;

struct EmployeeDetails
{
    int work_hours;
    double hourly_rate;
    string name;
};

void input_employees(EmployeeDetails* employees, int employees_no)
{
    for (int i = 0; i < employees_no; i++) 
    {
        cout << "Enter details for Employee " << i+1 << ":" << endl;
        
        cout << "Name: ";
        cin >> employees[i].name;
        
        cout << "Working Hours: ";
        cin >> employees[i].work_hours;
        
        cout << "Hourly Rate: ";
        cin >> employees[i].hourly_rate;
    }
}

void display_employees(EmployeeDetails* employees, int employees_no)
{
    cout << "Employee Salary Details: " << endl;
    
    for (int i = 0; i < employees_no; i++)
    {
        double salary = employees[i].work_hours * employees[i].hourly_rate;
        cout << "Name: " << employees[i].name << endl << "Working Hours: " << employees[i].work_hours << endl << "Hourly Rate: " << employees[i].hourly_rate<< endl << "Total Salary: " << salary << endl;
    }
}

int main() {
    
    int employees_no;

    cout << "Enter the number of employees: ";
    cin >> employees_no;

    EmployeeDetails* employees = new EmployeeDetails[employees_no];

    input_employees(employees, employees_no);
    display_employees(employees, employees_no);

    delete[]employees;

    return 0;
}
