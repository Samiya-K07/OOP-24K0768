#include<iostream>
#include<cmath>
using namespace std;

class Complex{
private:
    double real, imaginary; 

public:
    Complex(double a = 0, double b = 0) : real(a), imaginary(b){}

    Complex operator+(const Complex& c)
    {
        return Complex(this->real + c.real, this->imaginary + c.imaginary); 
    }
    
    Complex operator-(const Complex& c)
    {
        return Complex(this->real - c.real, this->imaginary - c.imaginary); 
    }
    
    Complex operator*(const Complex& c)
    {
        return Complex(this->real * c.real, this->imaginary * c.imaginary); 
    }
    
    Complex operator/(const Complex& c)
    {
        double denominator = c.real * c.real + c.imaginary * c.imaginary;
        return Complex((real * c.real + imaginary * c.imaginary) / denominator, (imaginary * c.real - real * c.imaginary) / denominator);    
    }

    friend ostream& operator<< (ostream& output, const Complex& c);
    friend double magnitude(Complex c);
};

ostream& operator<<(ostream& output, const Complex& c)
{
    output << c.real << " + " << c.imaginary << "i" << endl; 
    return output; 
}

double magnitude(Complex c)
{
    return sqrt(pow(c.real, 2) + pow(c.imaginary, 2)); 
}

int main()
{
    Complex c1(8, 6), c2(2, 3);

    cout << "c1: " << c1 << endl; 
    cout << "c2: " << c2 << endl;

    cout << "SUM: " << c1 + c2 << endl; 
    cout << "DIFFERENCE: " << c1 - c2 << endl; 
    cout << "PRODUCT: " << c1 * c2 << endl; 
    cout << "DIVISION: " << c1 / c2 << endl; 

    cout << "Absolute value of c1 is: " << magnitude(c1) << endl; 

    return 0;
}