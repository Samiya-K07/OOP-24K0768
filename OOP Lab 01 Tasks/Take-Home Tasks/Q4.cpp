//Samiya Khan
//24K-0768
//Take-Home Task 04

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

    cout << endl << "Monthly average AQI for each city:\n";
    
    double monthly_avg[4] = {0};
    
    for (int i = 0; i < 4; i++)
    {
        double sum = 0;
        for (int j = 0; j < 28; j++)
        {
            sum = sum + aqi_tracker[i][j];
        }
        
        monthly_avg[i] = sum/28;
        cout << cities[i] << "monthly average: " << monthly_avg[i] << endl;
    }
    
    double first_week_avg[4] = {0};
    double last_week_avg[4] = {0};
    double improvement[4] = {0};

    for (int i = 0; i < 4; i++) 
    {
        double first_week_sum = 0; 
        double last_week_sum = 0;
        
        for (int j = 0; j < 7; j++) 
        {
            first_week_sum = first_week_sum + aqi_tracker[i][j];
        }
        
        first_week_avg[i] = first_week_sum/7;

        for (int j = 21; j < 28; j++) 
        {
            last_week_sum = last_week_sum + aqi_tracker[i][j];
        }
        
        last_week_avg[i] = last_week_sum/7;
        improvement[i] = first_week_avg[i] - last_week_avg[i];
    }
    
    int most_improved_tracker = 0;
    double max_improvement = improvement[0];
    
    for (int i = 1; i < 4; i++) 
    {
        if (improvement[i] > max_improvement)
        {
            max_improvement = improvement[i];
            most_improved_tracker = i;
        }
    }
   
    cout << "The city with the most improved air quality is: " << cities[most_improved_tracker] << "with improvement of: " << max_improvement << endl;

    return 0;
}