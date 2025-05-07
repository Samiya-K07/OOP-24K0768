// Samiya Khan
// 24K-0768

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
    ifstream inputFile("vehicles.txt");
    
    if (!inputFile.is_open())
    {
        cout << "Failed to open the file" << endl;
        return 1;
    }

    string record;
    while (getline(inputFile, record))
    {
        if (record.empty())
        {
            continue;
        }
        
        if (record[0] == '#')
        {
            continue;
        }

        istringstream stream(record);

        string vehicleType, vehicleID, vehicleName, manufactureYear, detail, approvalStatus;

        getline(stream, vehicleType, ',');
        getline(stream, vehicleID, ',');
        getline(stream, vehicleName, ',');
        getline(stream, manufactureYear, ',');
        getline(stream, detail, ',');
        getline(stream, approvalStatus, ',');

        cout << "Vehicle Type: " << vehicleType << endl;
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Vehicle Name: " << vehicleName << endl;
        cout << "Manufacture Year: " << manufactureYear << endl;
        cout << "Details: (" << detail << " )" << endl;
        cout << "Approval Status: " << approvalStatus << endl;
        cout << endl;
    }

    inputFile.close();
    return 0;
}
