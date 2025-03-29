//Samiya Khann
//24K-0768

#include<iostream>
#include<string>
using namespace std;

class Person{
protected:
    string name;
    int age;
    string contactNumber;
    string address;

public:
    Person(string n, int a, string contact, string add) : name(n), age(a), contactNumber(contact), address(add) {}
    
    virtual void displayInfo() 
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contactNumber << endl;
        cout << "Address: " << address << endl;
    }
    
    virtual void updateInfo(string newContact, string newAddress) 
    {
        contactNumber = newContact;
        address = newAddress;
    }
    
};

class Patient : public Person{
private:
    int patientID;
    string medicalHistory;
    string doctorAssigned;

public:
    Patient(string n, int a, string contact, string add, int id, string history, string doctor) : Person(n, a, contact, add), patientID(id), medicalHistory(history), doctorAssigned(doctor) {}
    
    void displayInfo() 
    {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << endl;
        cout << "Medical History: " << medicalHistory << endl;
        cout << "Doctor Assigned: " << doctorAssigned << endl;
    }
};

class Doctor : public Person{
private:
    string specialization;
    double consultationFee;
    string patientsList;

public:
    Doctor(string n, int a, string contact, string add, string spec, double fee, string patients) : Person(n, a, contact, add), specialization(spec), consultationFee(fee), patientsList(patients) {}
    
    void displayInfo() 
    {
        Person::displayInfo();
        cout << "Specialization: " << specialization << endl;
        cout << "Consultation Fee: " << consultationFee << endl;
        cout << "Patients List: " << patientsList << endl;
    }
};

class Nurse : public Person{
private:
    string assignedWard;
    string shiftTimings;

public:
    Nurse(string n, int a, string contact, string addr, string ward, string shift) : Person(n, a, contact, addr), assignedWard(ward), shiftTimings(shift) {}
    
    void displayInfo(){
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << endl;
        cout << "Shift Timings: " << shiftTimings << endl;
    }
};

class Administrator : public Person{
private:
    string department;
    double salary;

public:
    Administrator(string n, int a, string contact, string add, string dept, double s) : Person(n, a, contact, add), department(dept), salary(s) {}
    
    void updateInfo(string newContact, string newAddress, double newSalary) 
    {
        Person::updateInfo(newContact, newAddress);
        salary = newSalary;
    }
};

int main() {
    
    Patient patient1("Uzair Khan", 40, "123-456-789", "ABC Street", 101, "Dermatologist", "Dr. Sana Khan");
    Doctor doctor1("Dr. Sarah Khan", 35, "345-876-189", "DEF Street", "Orthopedic", 250.0, "Jennie Kim, Ruby Jane");
    Nurse nurse1("Shakir", 27, "987-654-321", "123 Street", "Trauma Centre", "Late Night Shift");
    Administrator admin1("Ahmed", 52, "543-651-879", "XYZ street", "Marketing", 6000.0);

    patient1.displayInfo();
    cout << endl;
    
    doctor1.displayInfo();
    cout << endl;
    
    nurse1.displayInfo();
    cout << endl;
    
    return 0;
}