//Samiya Khan
//24K-0768
//Task 02

#include <iostream>
using namespace std;

int **create_matrix(int rows, int columns)
{
    int **matrix = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[columns];
    }
    
    return matrix;
}

void input_matrix(int **ptr, int rows, int columns, const string &name)
{
    cout << "Enter the " << name << " matrix:" << endl;
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "Enter the element for row " << i + 1 << " and column " << j + 1 << ":";
            cin >> ptr[i][j];
        }
    }
}

void display_matrix(int **ptr, int rows, int columns, const string &name)
{
    cout << name << " matrix:" << endl;
    
    for (int i = 0; i < rows; i++)
    {
        cout << "|";
        
        for (int j = 0; j < columns; j++)
        {
            cout << ptr[i][j] << "|";
        }
        
        cout << endl;
    }
}

int **add_matrices(int **first, int **second, int rows, int columns)
{
    int **result = create_matrix(rows, columns);
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
    
    return result;
}

int **subtract_matrices(int **first, int **second, int rows, int columns)
{
    int **result = create_matrix(rows, columns);
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            result[i][j] = first[i][j] - second[i][j];
        }
    }
    
    return result;
}

void free(int **ptr, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] ptr[i];
    }
    
    delete[] ptr;
}

int main() {

    int rows;
    int columns;
    
    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> columns;

    int **first = create_matrix(rows, columns);
    int **second = create_matrix(rows, columns);

    input_matrix(first, rows, columns, "First");
    input_matrix(second, rows, columns, "Second");

    int **sum_matrix = add_matrices(first, second, rows, columns);
    int **diff_matrix = subtract_matrices(first, second, rows, columns);

    display_matrix(first, rows, columns, "First");
    display_matrix(second, rows, columns, "Second");
    display_matrix(sum_matrix, rows, columns, "Sum");
    display_matrix(diff_matrix, rows, columns, "Difference");

    free(first, rows);
    free(second, rows);
    free(sum_matrix, rows);
    free(diff_matrix, rows);

    return 0;
}