//Samiya Khan
//24K-0768
//Task 04

#include <iostream>
#include <string>>
using namespace std;

class Car{

private:
    string brand;
    string model;
    float fuelCapacity;
    float currentFuelLevel;
    float consumption_rate;

public:
    Car(string brand_new, string model_new, float capacity, float consumption)
    {
        brand = brand_new;
        model = model_new;
        fuelCapacity = capacity;
        currentFuelLevel = capacity;
        consumption_rate = consumption;
    }

    void drive_car(float distance)
    {
        float fuelNeeded = distance * consumption_rate;

        if (fuelNeeded > currentFuelLevel) 
        {
            cout << "Error!! Not enough fuel to drive " << distance << " km!!" << endl;
        } 
        
        else 
        {
            currentFuelLevel -= fuelNeeded;
            cout << "You have driven " << distance << " km!! Remaining fuel: " << currentFuelLevel << " liters!!" << endl;
        }
        
        check_fuel_status();
    }

    void refuel_tank(float fuel_amount)
    {
        if (fuel_amount <= 0)
        {
            cout << "Invalid Error!! Fuel amount invalid!!" << endl;
            
            return;
        }

        if (currentFuelLevel + fuel_amount > fuelCapacity)
        {
            currentFuelLevel = fuelCapacity;
            cout << "Tank is now at full capacity!!" << endl;
        } 
        
        else 
        {
            currentFuelLevel += fuel_amount;
            cout << "Added " << fuel_amount << " liters!! Fuel level: " << currentFuelLevel << " liters!!" << endl;
        }
    }

    void check_fuel_status()
    {
        if (currentFuelLevel < (fuelCapacity * 0.15))
        {
            cout << "Warning!! Low fuel so refuel asap!!" << endl;
        }
    }

    void display_car_info()
    {
        cout << "Car Details:\n" << endl;
        cout << "Brand = " << brand << endl << "Model = " << model <<  endl << "Fuel Capacity = " << endl;
        cout << "Current Fuel Level = " << currentFuelLevel << " liters" << endl;
    }
};

int main() {
    
    Car zoya("Mehran", "BMW", 60, 0.22);

    zoya.display_car_info();
    zoya.drive_car(210);
    zoya.refuel_tank(80);
    zoya.drive_car(110);

    return 0;
}