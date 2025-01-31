//Samiya Khan
//24K-0768
//Take-Home Task 03

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
    
    cout << "Visual Representation:\n" << endl;
    
    for (int i = 0; i < 4; i++)
    {
        cout << endl << cities[i] << endl;
        
        for (int j = 0; j < 7; j++)
        {
            int star_tracker = aqi_tracker[i][j]/50;
            cout << "Day " << j+1  << " :";
            
            for (int k = 0; k < star_tracker; k++)
            {
                cout << "*";
            }
            
            cout << endl;
        }
    }
    
    return 0;
}