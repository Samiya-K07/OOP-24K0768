//Samiya Khan
//24K-0768
//Take-Home Task 02

#include <iostream>
using namespace std;

int main() {
    
    int aqi_tracker[4][7];
    string cities[4] = {"Islamabad", "Karachi", "Peshawar", "Lahore"};

    for (int i = 0; i < 4; i++)
    {
        cout << "Enter the AQI values for " << cities[i] << " for 07 days" << endl;
        
        for (int j = 0; j < 7; j++)
        {
            cout << "AQI value for day " << j + 1 << " :";
            cin >> aqi_tracker[i][j];
        }
    }
    
    cout << "Critical pollution days for each city:\n" << endl;
    
    for (int i = 0; i < 4; i++)
    {
        cout << cities[i] << " :";
       
        bool critical_day = false;
        
        for (int j = 0; j < 7; j++)
        {
           if(aqi_tracker[i][j] > 150)
           {
                cout << "Day " << j+1  << " ";
                critical_day = true;
            }
        } 
    
        if(!critical_day)
        {
            cout << "No critical days found" << endl;
        }
    }

    return 0;
}