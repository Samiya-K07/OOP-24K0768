//Samiya Khan
//24K-0768

#include<iostream>
#include<string>
using namespace std;

class Doctor{
public:
    string name;
    string specialization;
    int experience;

    Doctor(string n, string s, int e) : name(n), specialization(s), experience(e) {}

    void displayDetails() 
    {
        cout << "Doctor Name: " << name << "\nSpecialization: " << specialization << "\nExperience (years): " << experience << endl;
    }
};

class Hospital{
public:
    string name;
    Doctor* doctors[10];
    int doctorCount = 0;

    Hospital(string n) : name(n) {}

    void addDoctor(Doctor* d) 
    {
        if (doctorCount < 10) 
        {
            doctors[doctorCount++] = d;
        } 
        
        else 
        {
            cout << "Limit reached!! Cannot add more doctors!!" << endl;
        }
    }

    void displayDetails() 
    {
        cout << "Hospital Name: " << name << endl;
        cout << "Doctors Working: "<< endl;
        
        if (doctorCount == 0) 
        {
            cout << "No doctors assigned yet!!";
        } 
        
        else 
        {
            for (int i = 0; i < doctorCount; i++)
            {
                doctors[i]->displayDetails();
            }
        }
        
        cout << endl;
    }
};

int main() {
    Doctor doctor1("Dr. Abeer", "Orthopedic", 14);
    Doctor doctor2("Dr. Samiya", "Dermatologist", 7);
    Doctor doctor3("Dr. Umna", "Brain Surgeon", 20);

    Hospital hospital1("Indus Hospital");
    Hospital hospital2("Patel Hospital");

    hospital1.addDoctor(&doctor1);
    hospital1.addDoctor(&doctor2);
    hospital2.addDoctor(&doctor2);
    hospital2.addDoctor(&doctor3);

    hospital1.displayDetails();
    hospital2.displayDetails();

    return 0;
}