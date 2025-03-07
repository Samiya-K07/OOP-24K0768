//Samiya Khan
//24K-0768

#include<iostream>
#include<string>
using namespace std;

class Device{
protected:
    int deviceID;
    bool status;

public:
    Device(int new_id, bool new_stat) : deviceID(new_id), status(new_stat) {}

    void displayDetails() 
    {
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
    }
};

class SmartPhone:virtual public Device{
protected:
    float screenSize;

public:
    SmartPhone(int new_id, bool new_stat, float new_size) : Device(new_id, new_stat), screenSize(new_size) {}

    void displayDetails() 
    {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize  << endl;
    }
};

class SmartWatch:virtual public Device{

protected:
    bool heartRateMonitor;

public:
    SmartWatch(int new_id, bool new_stat, bool monitor) : Device(new_id, new_stat), heartRateMonitor(monitor) {}

    void displayDetails() 
    {
        Device::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
    }
};

class SmartWearable:public SmartPhone, public SmartWatch{
private:
    int stepCounter;

public:
    SmartWearable(int new_id, bool new_stat, float new_size, bool monitor, int counter) : Device(new_id, new_stat), SmartPhone(new_id, new_stat, new_size), SmartWatch(new_id, new_stat, monitor), stepCounter(counter) {}

    void displayDetails() 
    {
        SmartPhone::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
        cout << "Step Counter: " << stepCounter << endl;
    }
};

int main() {

    SmartWearable wear1(012, 2, 8, 2, 70);

    cout << "Smart Wearable Device Details:" << endl;
    wear1.displayDetails();

    return 0;
}