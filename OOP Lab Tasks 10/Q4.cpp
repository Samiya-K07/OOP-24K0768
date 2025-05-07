// Samiya Khan
// 24K-0768

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
    ifstream vehicleData("vehicles.txt");

    if (!vehicleData.is_open())
    {
        cout << "Error: Cannot access vehicles.txt" << endl;
        return 1;
    }

    string entry;
    while (getline(vehicleData, entry))
    {
        if (entry.empty())
        {
            continue;
        }
        
        if (entry[0] == '#')
        {
            continue;
        }

        istringstream reader(entry);
        string category, vehicleCode, vehicleName, yearInfo, details, approvalMark;

        getline(reader, category, ',');
        getline(reader, vehicleCode, ',');
        getline(reader, vehicleName, ',');
        getline(reader, yearInfo, ',');
        getline(reader, details, ',');
        getline(reader, approvalMark, ',');

        if (category == "AutonomousCar")
        {
            size_t separator = details.find(':');
            
            if (separator != string::npos)
            {
                string versionInfo = details.substr(separator + 1);
                float softwareVer = stof(versionInfo);
                cout << "Vehicle Code: " << vehicleCode << " | Software Version: " << softwareVer << endl;
            }
            
            else
            {
                cout << "Missing ':' in details for AutonomousCar with Code " << vehicleCode << endl;
            }
        }
        
        else if (category == "Electric Vehicle")
        {
            size_t separator = details.find(':');
            
            if (separator != string::npos)
            {
                string batteryInfo = details.substr(separator + 1);
                int batterySize = stoi(batteryInfo);
                cout << "Vehicle Code: " << vehicleCode << " | Battery Capacity: " << batterySize << endl;
            }
            
            else
            {
                cout << "Missing ':' in details for Electric Vehicle with Code " << vehicleCode << endl;
            }
        }
    }

    vehicleData.close();
    return 0;
}
