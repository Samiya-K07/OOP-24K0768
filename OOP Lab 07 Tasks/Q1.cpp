//Samiya Khan
//24K-0768

#include<iostream>
#include<string>
using namespace std;

class Device{
protected:
    int deviceID;
    string deviceName;
    bool status;
    string location;

public:
    Device(int id, string name, string l) : deviceID(id), deviceName(name), location(l), status(false) {}
    
    virtual void turnOn() 
    {
        status = true;
    }
    
    virtual void turnOff() 
    {
        status = false;
    }
    
    virtual void getStatus() 
    {
        cout << deviceName << " is " << (status ? "On" : "Off") << endl;
    }
    
    virtual void displayInfo() const 
    {
        cout << "Device ID: " << deviceID << "\nName: " << deviceName << "\nLocation: " << location << "\nStatus: " << (status ? "On" : "Off") << endl;
    }
};

class Light : public Device{
private:
    int brightnessLevel;
    string colorMode;

public:
    Light(int id, string name, string l, int brightness, string color) : Device(id, name, l), brightnessLevel(brightness), colorMode(color) {}

    void displayInfo() 
    {
        Device::displayInfo();
        cout << "Brightness Level: " << brightnessLevel << "\nColor Mode: " << colorMode << endl;
    }
};

class Thermostat : public Device{
private:
    float temperature;
    string mode;
    float targetTemperature;

public:
    Thermostat(int id, string name, string l, float temp, string m, float target) : Device(id, name, l), temperature(temp), mode(m), targetTemperature(target) {}

    void getStatus() 
    {
        cout << deviceName << " is " << (status ? "On" : "Off") << "\nCurrent Temperature: " << temperature << endl;
    }
};

class SecurityCamera : public Device{
private:
    string resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

public:
    SecurityCamera(int id, string name, string l, string r, bool night) : Device(id, name, l), resolution(r), nightVisionEnabled(night), recordingStatus(false) {}

    void turnOn()
    {
        status = true;
        recordingStatus = true;
        cout << deviceName << " is now recording!!" << endl;
    }
};

class SmartPlug : public Device{
private:
    float powerConsumptiom;
    int timerSetting;

public:
    SmartPlug(int id, string name, string l, float p, int t) : Device(id, name, l), powerConsumptiom(p), timerSetting(t) {}

    void turnOff() 
    {
        status = false;
        cout << deviceName << " successfully turned off!! Power usage: " << powerConsumptiom << endl;
    }
};

int main() {
    
    Light light1(35, "Light Bulb", "Lounge", 85, "Red Light");
    Thermostat thermostat1(55, "Room Thermostat", "Bed Room", 33.9, "Cooling", 36);
    SecurityCamera securitycamera1(77, "Back Gate Camera", "Exit", "1040p", true);
    SmartPlug smartplug1(99, "Home Plug", "Dining Room", 69.5, 35);

    light1.displayInfo();
    thermostat1.getStatus();
    securitycamera1.turnOn();
    smartplug1.turnOff();

    return 0;
}