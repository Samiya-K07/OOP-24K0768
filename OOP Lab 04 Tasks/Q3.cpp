//Samiya Khan
//24K-0768
//Task 03

#include<iostream>
#include<string>
using namespace std;

class Car{
    
    private:
    string brand;
    string model;
    float price;
    bool availability;

    public:
    Car() {
        brand = "Unknown";
        model = "Generic";
        price = 0.0;
        availability = true;
    }
    
    Car (string b, string m, float p, bool a)
    {
        brand = b;
        model = m;
        price = p;
        availability = a;
    }

    Car(Car &obj)
    {
        brand = obj.brand;
        model = obj.model;
        price = obj.price;
        availability = obj.availability;
    }
    
    void update_details(string b, string m, float p, bool a) 
    {
        brand = b;
        model = m;
        price = p;
        availability = a;
    }

    void display()
    {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
        cout << "Availability Status: " << availability << endl;
    }
    
    ~Car()
    {
        cout << "Car " << brand << " " << model << " has been destroyed!!" << endl;
    }

};

int main() {
    
    Car car_1;
    car_1.display();
    Car car_2(car_1);
    car_1.update_details("Mehran", "BMW", 4000.0, true);
    car_1.display();
    car_2.display();

    return 0;
}