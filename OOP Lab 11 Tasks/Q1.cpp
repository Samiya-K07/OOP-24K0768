// Samiya Khan
// 24K-0768

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;

class DimensionMismatchException : public exception
{
private:
    string message;

public:
    DimensionMismatchException(int r1, int c1, int r2, int c2)
    {
        stringstream ss;
        ss << "DimensionMismatchException: Matrices must have same dimensions (" << r1 << "x" << c1 << " vs " << r2 << "x" << c2 << ")";
        message = ss.str();
    }

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

template <typename T>
class Matrix
{
private:
    int rows, cols;
    T **data;

public:
    Matrix(int r, int c) : rows(r), cols(c)
    {
        data = new T *[rows];
        for (int i = 0; i < rows; ++i)
        {
            data[i] = new T[cols];
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; ++i)
        {
            delete[] data[i];
        }
        delete[] data;
    }

    void inputMatrix()
    {
        cout << "Enter values for " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cin >> data[i][j];
            }
        }
    }

    void displayMatrix() const
    {
        cout << "Matrix (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << data[i][j] << "\t";
            }

            cout << endl;
        }
    }

    Matrix<T> operator+(const Matrix<T> &other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            throw DimensionMismatchException(rows, cols, other.rows, other.cols);
        }

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
};

int main()
{
    try
    {
        Matrix<int> A(2, 2);
        Matrix<int> B(3, 3);

        cout << "Matrix A Input:\n";
        A.inputMatrix();

        cout << "Matrix B Input:\n";
        B.inputMatrix();

        cout << "\nAttempting Matrix Addition...\n";
        Matrix<int> result = A + B;

        result.displayMatrix();
    }
    catch (const DimensionMismatchException &ex)
    {
        cout << "Exception Caught: " << ex.what() << endl;
    }

    return 0;
}
