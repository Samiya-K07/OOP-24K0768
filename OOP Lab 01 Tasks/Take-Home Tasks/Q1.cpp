//Samiya Khan
//24K-0768
//Take-Home Task 01

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

    int highest_avg_city = 0;
    double highest_avg_aqi = 0.0;

    cout << "Average AQI for each city:\n" << endl;
    for (int i = 0; i < 4; i++)
    {
        double sum = 0;
        
        for (int j = 0; j < 7; j++)
        {
            sum = sum + aqi_tracker[i][j];
        }
        
        double average = sum/7;
        cout << cities[i] << " average AQI: " << average << endl;

        if(average > highest_avg_aqi)
        {
            highest_avg_aqi = average;
            highest_avg_city = i;
        }
    }

    cout << "The city having the worst air quality is: " << cities[highest_avg_city] << " with the average AQI of: " << highest_avg_aqi << endl;

    return 0;
}