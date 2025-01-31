//Samiya Khan
//24K-0768
//Take-Home Task 05

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

    double weekly_avg[4][4] = {0};
    for (int i = 0; i < 4; i++)
    {
        for (int week = 0; week < 4; week++)
        {
            double sum = 0;
            
            for (int day = week * 7; day < (week + 1) * 7; day++)
            {
                sum = sum + aqi_tracker[i][day];
            }
            
            weekly_avg[i][week] = sum/7;
        }
    }

    cout << endl << "Critical pollution days:" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << cities[i] << ": ";
        
        for (int j = 0; j < 28; j++)
        {
            if (aqi_tracker[i][j] > 150)
            {
                cout << "Day " << j + 1 << " ";
            }
        }
        
        cout << endl;
    }

    int highest[4] = {0};
    int lowest[4] = {1000};
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 28; j++)
        {
            if (aqi_tracker[i][j] > highest[i]) 
            {
                highest[i] = aqi_tracker[i][j];
            }

            if (aqi_tracker[i][j]<lowest[i]) 
            {
                lowest[i] = aqi_tracker[i][j];
            }
        }
    }

    cout << "Weekly averages for each city:" << endl;
    cout << "City\t" << "Week 01\t" << "Week 02\t" <<"Week 03\t" << "Week 04" << endl;
    
    for (int i = 1; i <= 4; i++)
    {
        cout << cities[i];
        for (int week = 0; week < 4; week++)
        {
            cout << "\t "<< weekly_avg[i][week];
        }
        
        cout << endl;
    }
    
    cout << "Highest and Lowest AQI values:" << endl;
    cout << "City\t" << "Highest\t" << "Lowest\t"<< endl;
    
    for (int i = 1; i <= 4; i++)
    {
        cout << cities[i] << "\t" << highest[i] << "\t" << lowest[i] << endl;
    }
    
    return 0;
}