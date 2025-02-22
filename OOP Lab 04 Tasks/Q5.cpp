//Samiya Khan
//24K-0768
//Task 05

#include<iostream>
#include<string>
using namespace std;

class Car{
    
    private:
    string brand;
    string model;
    float price;
    bool availability;
    double total_revenue;
    string car_id;

    public:
    Car() : brand("Unknown"), model("Generic"), price(0.0), availability(true), total_revenue(0.0), car_id("000000") {}

    Car(string b, string m, double p, bool a, string id) : brand(b), model(m), price(p), availability(a), total_revenue(0.0), car_id(id) {}
    

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

    double apply_discount(int days) 
    {
        if (days > 5) 
        {
            return price * 0.95;
        } 
        
        else if (days > 10) 
        {
            return price * 0.90;
        }
        
        return price;
    }
    
    void rent_car(int days) 
    {
        if(availability) 
        {
            availability = false;
            
            double final_price = apply_discount(days);
            double revenue = final_price*days;
            total_revenue += revenue;
            
            cout << "The car " << brand << " " << model << " has been rented for " << days << " days at a price of " << apply_discount(days) << endl;
            cout << "Total revenue generated: " << total_revenue << endl;
        } 
        
        else 
        {
            cout << "The car " << brand << " " << model << " has already been rented!!" << endl;
        }
    }

    void display()
    {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
        cout << "Availability Status: " << availability << endl;
        cout << "Total Revenue: " << total_revenue << endl;
    }
};

int main() {
   
    Car car_1("Mehran", "BMW", 4000.0, true, "K-0768");
    cout << "Car 01 Details:\n" << endl;
    car_1.display();
    
    Car car_2("Toyota", "Corolla", 6000.0, true, "K-0881");
    cout << "Car 2 Details" << endl;
    car_2.display();
    
    car_1.rent_car(13);
    cout << "Car 01 Details:" << endl;
    car_1.display();

    return 0;
}