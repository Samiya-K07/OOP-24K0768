//Samiya Khan
//24K-0768
//In-Lab Task 03

#include <iostream>
using namespace std;

int main() {
    
    const int max = 6;
    const int fixed_donation = 10;

    string event_01[max];
    string event_02[max];
    
    int counter_01;
    int counter_02;


    cout << "Enter the amount of participants for event 01: ";
    cin >> counter_01;

    if(counter_01 > max)
    {
        counter_01 = max;
        cout << "Error!! Only " << max << " participants are allowed!!" << endl;
    }

    cout << "Enter the name of participants for event 01" << endl;
    
    for (int i = 1; i <= counter_01; i++)
    {
        cout << "Name of participant " << i+1 << ": ";
        cin >> event_01[i];
    }

    cout << "Enter the number of participants for event 02: ";
    cin >> counter_02;

    if(counter_02 > max)
    {
        counter_02 = max;
        cout << "Error!! Only " << max << " participants are allowed!!" << endl;
    }

    cout << "Enter name of participants for event 02" << endl;
    
    for (int i = 1; i <= counter_02; i++)
    {
        cout << "Name of participant " << i+1 << ": ";
        cin >> event_02[i];
    }
    
    int total_donation = fixed_donation * counter_01 * counter_02;
    cout << "The total donation from both events is: " << total_donation;
    
    return 0;
}