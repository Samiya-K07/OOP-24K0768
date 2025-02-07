//Samiya Khan
//24K-0768
//Task 05

#include <iostream>
using namespace std;

int main() {
    
    int elements_no;

    cout << "Enter the number of elements: ";
    cin >> elements_no;

    int* array = new int[elements_no];

    for (int i = 0; i < elements_no; i++)
    {
        cout << "Enter the " << i + 1 << " element: ";
        cin >> *(array+i);
    }

    cout << "Array elements: ";
    
    for (int i = 0; i < elements_no; i++)
    {
        cout << *(array+i) << " ";
    }
    cout << endl;

    int sum = 0;
    int *ptr = array;
    
    for (int i = 0; i < elements_no; i++)
    {
        sum = sum + *(ptr+i);
    }

    cout << "Total sum of the array elements: " << sum << endl;

    delete[]array;

    return 0;
}