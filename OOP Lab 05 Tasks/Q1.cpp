//Samiya Khan
//24K-0768

#include<iostream>
#include<cstring>
using namespace std;

class Apartment{
public:
    int ID;
    string address;
    char* name;

    Apartment(int i, string a, char* n) 
    {
        ID = i;
        address = a;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    Apartment(const Apartment &obj) 
    {
        ID = obj.ID;
        address = obj.address;
        name = obj.name;
    }

    void displayDetails() 
    {
        cout << "Apartment ID: " << ID << "\nAddress: " << address << "\nOwner Name: " << name << endl;
    }

    ~Apartment() {
        delete[] name;
    }
};

int main() {
    Apartment apartment1(102, "Main Street", "Samiya");
    cout << "Original Apartment: " << endl;
    apartment1.displayDetails();

    Apartment apartment2(apartment1);
    cout << "Copied Apartment: " << endl;
    apartment2.displayDetails();

    return 0;
}