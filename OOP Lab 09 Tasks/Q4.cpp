#include<iostream>
using namespace std;

class WeatherSensor
{
public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
    virtual ~WeatherSensor() {}
};

class Thermometer : public WeatherSensor
{
private:
    float temperature;

public:
    void readData()
    {
        temperature = 25.0;
    }

    void displayReport()
    {
        cout << "Thermometer Reading: " << temperature << endl;
    }
};

class Barometer : public WeatherSensor
{
private:
    float pressure;

public:
    void readData()
    {
        pressure = 1011.5;
    }

    void displayReport()
    {
        cout << "Barometer Reading: " << pressure << endl;
    }
};

int main()
{
    Thermometer t1;
    Barometer b1;

    WeatherSensor *sensors[2];
    
    sensors[0] = &t1;
    sensors[1] = &b1;

    for (int i = 0; i < 2; i++)
    {
        sensors[i]->readData();
        sensors[i]->displayReport();
    }

    for (int i = 0; i < 2; i++)
    {
        delete sensors[i];
    }

    return 0;
}