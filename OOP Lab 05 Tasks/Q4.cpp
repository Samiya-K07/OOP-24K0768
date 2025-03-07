//Samiya Khan
//24K-0768

#include<iostream>
#include<string>
using namespace std;

class AlarmSystem{
public:
    string level;

    AlarmSystem(string l) : level(l) {}

    void displayDetails() 
    {
        cout << "Security Level: " << level << endl;
    }
};

class SmartHome{
public:
    AlarmSystem alarm;

    SmartHome(string a) : alarm(a) {}

    void display() 
    {
        cout << "Smart Home Security Details:" << endl;
        alarm.displayDetails();
    }
};

int main() {
    
    SmartHome home1("Medium");

    home1.display();

    return 0;
}