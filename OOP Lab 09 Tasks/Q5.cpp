#include<iostream>
using namespace std;

class Shipment
{
protected:
    string trackingNumber;
    double weight;

public:
    Shipment(string t, double w) : trackingNumber(t), weight(w) {}

    virtual void estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;
    virtual ~Shipment() {}
};

class AirFreight : public Shipment
{
public:
    AirFreight(string t, double w) : Shipment(t, w) {}

    void estimateDeliveryTime() override
    {
        cout << "Estimated Delivery Time for Air Freight: 4-5 days!!" << endl;
    }

    void showDetails() override
    {
        cout << "Air Freight\nTracking Number: " << trackingNumber << "\nWeight: " << weight << endl;
    }
};

class GroundShipment : public Shipment
{
public:
    GroundShipment(string t, double w) : Shipment(t, w) {}

    void estimateDeliveryTime() override
    {
        cout << "Estimated Delivery Time for Ground Shipment: 1-3 days!!" << endl;
    }

    void showDetails() override
    {
        cout << "Ground Shipment\nTracking Number: " << trackingNumber << "\nWeight: " << weight << endl;
    }
};

int main()
{
    AirFreight af("AF101", 11.0);
    GroundShipment gs("GS102", 35.3);

    Shipment *shipment[2];
    shipment[0] = &af;
    shipment[1] = &gs;

    for (int i = 0; i < 2; i++)
    {
        shipment[i]->showDetails();
        shipment[i]->estimateDeliveryTime();
        cout << endl;
    }

    for (int i = 0; i < 2; i++)
    {
        delete shipment[i];
    }

    return 0;
}