#include<iostream>
using namespace std;

//        0    1
//   0   num1 num2
//   1   num3 num4

class MatrixHelper;

class Matrix2x2{
private:
    int num1, num2, num3, num4;

public:
    Matrix2x2(){} 
    Matrix2x2(int n1, int n2, int n3, int n4) : num1(n1), num2(n2), num3(n3), num4(n4){}

    Matrix2x2 operator+(const Matrix2x2& m)
    {
        return Matrix2x2(this->num1 + m.num1, this->num2 + m.num2, this->num3 + m.num3, this->num4 + m.num4);
    }

    Matrix2x2 operator-(const Matrix2x2& m)
    {
        return Matrix2x2(this->num1 - m.num1, this->num2 - m.num2, this->num3 - m.num3, this->num4 - m.num4);
    }
    
    Matrix2x2 operator*(const Matrix2x2& m)
    {
        return Matrix2x2(this->num1 * m.num1, this->num2 * m.num2, this->num3 * m.num3, this->num4 * m.num4);
    }    

    friend class MatrixHelper;
    friend ostream& operator<<(ostream& output, const Matrix2x2& m);
    friend int determinant(const Matrix2x2& m); 
};

class MatrixHelper{
public:
    void updateMatrix(Matrix2x2& m, int row, int column, int value) 
    {
        if (row == 0 && column == 0)
        {
            m.num1 = value;
        }

        else if (row == 0 && column == 1)
        {
            m.num2 = value;
        }

        else if (row == 1 && column == 0)
        {
            m.num3 = value;
        }

        else if (row == 1 && column == 1)
        {
            m.num4 = value; 
        }

        else
        {
            cout << "Invalid input for row and column!!" << endl;
            exit(0); 
        }
    }
};

int determinant(const Matrix2x2& m)
{
    return (m.num1 * m.num4) - (m.num2 * m.num3);
}

ostream& operator<<(ostream& output, const Matrix2x2& m)
{
    output << m.num1 << " " << m.num2 << endl
           << m.num3 << " " << m.num4 << endl; 

    return output;
}

int main(){

    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);

    cout << "SUM: " << endl << m1 + m2 << endl;
    cout << "DIFF: " << endl << m1 - m2 << endl;
    cout << "PRODUCT: " << endl << m1 * m2 << endl;

    cout << "Determinant of m1: " << determinant(m1) << endl; 
    MatrixHelper mh1; 
    mh1.updateMatrix(m2, 0, 0, 9); 
    cout << "Updated m2 Matrix:" << endl;
    cout << m2 << endl;  

    return 0;
}