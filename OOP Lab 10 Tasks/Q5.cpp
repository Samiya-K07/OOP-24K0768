// Samiya Khan
// 24K-0768

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
    ifstream inputFile("fleet_info.txt");

    if (!inputFile.is_open())
    {
        cout << "Unable to open the specified file." << endl;
        return 1;
    }

    string currentLine;
    while (getline(inputFile, currentLine))
    {
        if (currentLine.empty() || currentLine[0] == '#')
        {
            continue;
        }

        istringstream parser(currentLine);
        string category, vehicleID, modelName, manufactureYear, details, approval;

        getline(parser, category, ',');
        getline(parser, vehicleID, ',');
        getline(parser, modelName, ',');
        getline(parser, manufactureYear, ',');
        getline(parser, details, ',');
        getline(parser, approval, ',');

        if (category == "SelfDriving")
        {
            size_t delimiter = details.find(':');
            if (delimiter != string::npos)
            {
                string versionData = details.substr(delimiter + 1);
                float version = stof(versionData);
                cout << "ID: " << vehicleID << " | Software Ver: " << version << endl;
            }
           
            else
            {
                cout << "Missing ':' in details for SelfDriving vehicle ID " << vehicleID << endl;
            }
        }
        
        else if (category == "EV")
        {
            size_t delimiter = details.find(':');
            
            if (delimiter != string::npos)
            {
                string batteryData = details.substr(delimiter + 1);
                int battery = stoi(batteryData);
                cout << "ID: " << vehicleID << " | Battery: " << battery << " kWh" << endl;
            }
            
            else
            {
                cout << "Missing ':' in details for EV ID " << vehicleID << endl;
            }
        }
        
        else if (category == "Hybrid")
        {
            size_t firstColon = details.find(':');
            size_t separator = details.find('|');
            size_t secondColon = details.find(':', separator);

            if (firstColon != string::npos && separator != string::npos && secondColon != string::npos)
            {
                string cargo = details.substr(firstColon + 1, separator - firstColon - 1);
                int cargoCapacity = stoi(cargo);

                string battery = details.substr(secondColon + 1);
                int batteryCapacity = stoi(battery);

                cout << "ID: " << vehicleID << " | Cargo: " << cargoCapacity << " kg | Battery: " << batteryCapacity << " kWh" << endl;
            }
            
            else
            {
                cout << "Incorrect format in details for Hybrid ID " << vehicleID << endl;
            }
        }
        
        else
        {
            cout << "Unrecognized vehicle category '" << category << "' for ID " << vehicleID << endl;
        }
    }

    inputFile.close();
    return 0;
}
