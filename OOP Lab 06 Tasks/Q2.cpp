//Samiya Khan
//24K-0768

#include<iostream>
#include<string>
using namespace std;

class Vehicle{
protected:
    string brand;
    int speed;

public:
    Vehicle(string new_brand, int new_speed) : brand(new_brand), speed(new_speed) {}

    void displayDetails() 
    {
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << endl;
    }
};

class Car:public Vehicle{
protected:
    int seats;

public:
    Car(string new_brand, int new_speed, int new_seats) : Vehicle(new_brand, new_speed), seats(new_seats) {}

    void displayDetails() 
    {
        Vehicle::displayDetails();
        cout << "Seats: " << seats << endl;
    }
};

class ElectricCar:public Car{  
private:
    int batteryLife;

public:
    ElectricCar(string new_brand, int new_speed, int new_seats, int new_batteryLife) : Car(new_brand, new_speed, new_seats), batteryLife(new_batteryLife) {}

    void displayDetails() 
    {
        Car::displayDetails();
        cout << "Battery Life: " << batteryLife << endl;
    }
};

int main() {

    ElectricCar electricCar_1("BMW", 300, 5, 10);

    cout << "Electric Car Details:" << endl;
    electricCar_1.displayDetails();

    return 0;
}