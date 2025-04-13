#include<iostream>
#include<string>
using namespace std;

class Car{
private:
    string model;
    double price;

public:
    Car(string mmodel, double pprice) : model(mmodel), price(pprice) {}

    friend class InventoryManager;

    friend void compare(const Car& c1, const Car& c2);
};

class InventoryManager{
public:
    void update(Car& car, double newPrice) 
    {
        car.price = newPrice;
        cout << "Updated price of " << car.model << " is: " << car.price << endl;
    }

    void display(const Car& car) 
    {
        cout << "Model: " << car.model << endl;
        cout << "Price: " << car.price << endl;
    }
};

void compare(const Car& c1, const Car& c2) 
{
    if (c1.price > c2.price) 
    {
        cout << c1.model << " is more expensive than " << c2.model << endl;
    } 
    
    else if (c1.price < c2.price) 
    {
        cout << c2.model << " is more expensive than " << c1.model << endl;
    } 
    
    else {
        cout << "Both the cars have the same price!!" << endl;
    }
}

int main(){
   
    Car c1("Honda CR-V", 60000);
    Car c2("Hyundai Tucson", 70000);
    
    InventoryManager m1;

    m1.display(c1);
    m1.display(c2);

    m1.update(c1, 55000);

    compare(c1, c2);

    return 0;
}