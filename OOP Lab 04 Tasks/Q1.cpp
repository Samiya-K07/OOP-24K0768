//Samiya Khan
//24K-0768
//Task 01

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
    
    void update_details(string b, string m, float p, bool a) 
    {
        brand = b;
        model = m;
        price = p;
        availability = a;
    }

    bool check_availability() 
    {
        if(availability) 
        {
            cout << "The car " << brand << " " << model << " is available!!"<< endl;
        } 
        
        else 
        {
            cout << "Oops...the car " << brand << " " << model << " is not available!!"<< endl;
        }
    }

    void rent_car() 
    {
        if(availability) 
        {
            availability = false;
            cout << "The car " << brand << " " << model << " has been rented successfully!!"<< endl;
        } 
        
        else 
        {
            cout << "The car " << brand << " " << model << " has already been rented!!"<< endl;
        }
    }

    void display()
    {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
        cout << "Availability Status: " << availability << endl;
    }
};

int main() {
    
    Car car_1;
    car_1.display();
    car_1.update_details("Mehran", "BMW", 4000.0, true);
    car_1.display();
    car_1.check_availability();
    car_1.rent_car();
    car_1.check_availability();
    
    return 0;
}