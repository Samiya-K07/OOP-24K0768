//Samiya Khan
//24K-0768

#include<iostream>
#include<string>
using namespace std;

class Person{
protected:
    string name;
    int age;

public:
    Person(string new_name, int new_age) : name(new_name), age(new_age) {}

    void displayDetails() 
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Teacher:virtual public Person{
protected:
    string subject;

public:
    Teacher(string new_name, int new_age, string new_subject) : Person(new_name, new_age), subject(new_subject) {}

    void displayDetails() 
    {
        Person::displayDetails();
        cout << "Subject Expertise: " << subject << endl;
    }
};

class Researcher:virtual public Person{
protected:
    string researchArea;

public:
    Researcher(string new_name, int new_age, string new_ra) : Person(new_name, new_age), researchArea(new_ra) {}

    void displayDetails() 
    {
        Person::displayDetails();
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor:public Teacher, public Researcher{

private:
    int publications;

public:
    Professor(string new_name, int new_age, string new_subject, string new_ra, int new_pub) 
        : Person(new_name, new_age), Teacher(new_name, new_age, new_subject), Researcher(new_name, new_age, new_ra), publications(new_pub) {}

    void displayDetails() 
    {
        Person::displayDetails();
        
        cout << "Subject Expertise: " << subject << endl;
        cout << "Research Area: " << researchArea << endl;
        cout << "Publications: " << publications << endl;
    }
};

int main() {

    Professor professor_1("Samiya Khan", 36, "English Literature", "Hamlet", 06);

    cout << "Professor Details:" << endl;
    professor_1.displayDetails();

    return 0;
}