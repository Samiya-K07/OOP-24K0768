//Samiya Khan
//24K-0768
//Task 07

#include <iostream>
using namespace std;

int main() {
    
    int row_01;
    int column_01;
    
    int row_02;
    int column_02;

    cout << "Enter the rows and columns for 1st matrix: ";
    cin >> row_01 >> column_01;
    
    cout << "Enter the rows and columns for 2nd matrix: ";
    cin >> row_02 >> column_02;

    if (column_01 != row_02)
    {
        cout << "Matrix multiplication is not possible!! Make sure the column of first matrix and row of second matrix are equal!!" << endl;
        return 1;
    }

    int** a = new int*[row_01];
    int** b = new int*[row_02];
    
    int** result = new int*[row_01];

    for (int i = 0; i < row_01; i++)
    {
        a[i] = new int[column_01];
    }
    
    for (int i = 0; i < row_02; i++)
    {
        b[i] = new int[column_02];
    }
    
    for (int i = 0; i < row_01; i++)
    {
        result[i] = new int[column_02];
    }

    cout << "Enter the elements of 1st matrix: " << endl;
    for (int i = 0; i < row_01; i++)
    {
        for (int j = 0; j < column_01; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "Enter the elements of 2nd matrix: " << endl;
    for (int i = 0; i < row_02; i++)
    {
        for (int j = 0; j < column_02; j++)
        {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < row_01; i++)
    {
        for (int j = 0; j < column_02; j++)
        {
            result[i][j] = 0;
            
            for (int k = 0; k < column_01; k++)
            {
                result[i][j] = result[i][j] + (a[i][k] * b[k][j]);
            }
        }
    }

    cout << "Multiplication of matrix:" << endl;
    for (int i = 0; i < row_01; i++)
    {
        cout << "|";
        for (int j = 0; j < column_02; j++)
        {
            cout << result[i][j] << "|";
        }
        
        cout << endl;
    }

    for (int i = 0; i < row_01; i++)
    {
        delete[] a[i];
    }
    
    for (int i = 0; i < row_02; i++)
    {
        delete[] b[i];
    }
    
    for (int i = 0; i < row_01; i++)
    {
        delete[] result[i];
    }

    delete[] a;
    delete[] b;
    delete[] result;

    return 0;
}