#include <iostream>
#include <string>
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

    Car(string br, string mdl, float pr, bool available){
        brand =br;
        model = mdl;
        price = pr;
        availability = available;
    }

    void updateDetails(string br, string mdl, float pr, bool available) {
        brand = br;
        model = mdl;
        price = pr;
        availability = available;
    }

    bool checkAvailability() {
        if(availability) {
            cout << "The car " << brand << " " << model << " ia available"<< endl;
        } else {
            cout << "The car " << brand << " " << model << " is not available"<< endl;
        }
    }

    double applyDiscount(int days) {
        if (days>5) {
            return price * 0.95;
        } else if (days>10) {
            return price * 0.90;
        }
        return price;
    }

    void rentCar(int days) {
        if(availability) {
            availability = false;
            cout << "The car " << brand << " " << model << " has been rented for " << days << " days at a price of " << applyDiscount(days) << endl;
        } else {
            cout << "The car " << brand << " " << model << " is already rented"<< endl;
        }
    }

    void display(){
        cout << "Brand: " << brand << ", Model: " << model << ", Price: " << price << ", Availability: " << availability << endl;
    }
};

int main () {
    Car car1("Toyota", "Corolla", 3000.0, true);
    car1.display();
    car1.rentCar(7);
    car1.checkAvailability();

    return 0;
}