//Samiya Khan
//24K-0768
//In-Lab Task 04

#include <iostream>
using namespace std;

int main() {
    
    const int max = 6;
    
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
    
    cout << "Participants of event 01:\n" << endl;
    
    for (int i = counter_01 - 1; i >= 0; i--)
    {
       cout << event_01[i] << endl;
    }

    cout << "Participants of event 02:\n" << endl;
    
    for (int i = counter_02 - 1; i >= 0; i--)
    {
       cout << event_02[i] << endl;
    }
    
    return 0;
}