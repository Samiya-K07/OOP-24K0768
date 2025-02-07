//Samiya Khan
//24K-0768
//Task 04

#include <iostream>
#include <string>
using namespace std;

void bubble_sort(string* array, int m)
{
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < (m -i-1); j++)
        {
            if (array[j] > array[j+1])
            {
                string temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main() {
    
    int strings_no;

    cout << "Enter the number of strings: ";
    cin >> strings_no;

    string* array = new string[strings_no];

    cout << "Enter " << strings_no << " strings:\n";
    
    for (int i = 0; i < strings_no; i++)
    {
        cout << "String " << i+1 << ": ";
        cin >> array[i];
    }

    bubble_sort(array, strings_no);

    cout << "Sorted Strings: " << endl;
    
    for (int i = 0; i < strings_no; i++)
    {
        cout << array[i] << endl;
    }

    delete[]array;

    return 0;
}