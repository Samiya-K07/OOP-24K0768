//Samiya Khan
//24K-0768
//Task 06

#include <iostream>
using namespace std;

struct Student
{
    int roll_no;
    float marks[3];
    string name;
};

float average(float marks[])
{
    float sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum = sum + marks[i];
    }
    
    return sum/3;
}

int main() {
    
    int student_count;

    cout << "Enter the number of students: ";
    cin >> student_count;

    Student* students = new Student[student_count];

    for (int i = 0; i < student_count; i++)
    {
        cout << "Enter the details of student " << i+1 << ": " << endl;

        cout << "Name: ";
        cin >> students[i].name;

        cout << "Roll Number: ";
        cin >> students[i].roll_no;
       
        cout << "Enter marks in the 3 subjects:" << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter marks for subject " << j+1 << ": ";
            cin >> students[i].marks[j];
        }
    }

    cout << "Records of students:" << endl;
    
    for (int i = 0; i < student_count; i++)
    {
        cout << "Records of student " << i+1 << " : " <<endl;
        
        cout << "Name: " << students[i].name << endl;
        cout << "Roll no: " << students[i].roll_no << endl;
        cout << "Marks: " << students[i].marks[0] << ", " << students[i].marks[1] << "and, " << students[i].marks[2] << endl;
        cout << "Average marks: " << average(students[i].marks) << endl;
    }

    delete[]students;

    return 0;
}