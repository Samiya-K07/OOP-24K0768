//Samiya Khan
//24K-0768
//Task 10

#include <iostream>
using namespace std;

int main() {
    
    int a, b, c;

    cout << "Enter the dimensions for the 3D array: " << endl;
    cin >> a >> b >> c;

    int*** array = new int**[a];
    
    for (int i = 0; i < a; i++)
    {
        array[i] = new int*[b];
        
        for (int j = 0; j < b; j++)
        {
            array[i][j] = new int[c];
        }
    }

    cout << "Enter " << (a * b * c) << " elements:" << endl;
    
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            for (int k = 0; k < c; k++)
            {
                cin >> array[i][j][k];
            }
        }
    }

    cout << "Elements of the 3D array:" <<endl;
    for (int i = 0; i < a; i++)
    {
        cout << "-------" << endl;
        
        for (int j = 0; j < b; j++)
        {
            for (int k = 0; k < c; k++)
            {
                cout << array[i][j][k] << " ";
            }
        }
        
        cout << endl;
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            delete[] array[i][j];
        }
        
        delete[] array[i];
    }
    
    delete[] array;

    return 0;
}