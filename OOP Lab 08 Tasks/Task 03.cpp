#include<iostream>
using namespace std;

class Vector2D{
private:
    double x;
    double y;

public:
    Vector2D(double x = 0, double y = 0) 
    {
        this->x = x;
        this->y = y;
    }

    Vector2D operator+(const Vector2D& v) 
    {
        return Vector2D(x + v.x, y + v.y);
    }

    Vector2D operator-(const Vector2D& v) 
    {
        return Vector2D(x - v.x, y - v.y);
    }

    Vector2D operator*(double scalar) 
    {
        return Vector2D(x * scalar, y * scalar);
    }

    friend double dotProduct(const Vector2D& v1, const Vector2D& v2);

    friend ostream& operator<<(ostream& output, const Vector2D& v);
};

ostream& operator<<(ostream& output, const Vector2D& v)
{
    output << "Vector: (" << v.x << ", " << v.y << ")" << endl; 
}

double dotProduct(const Vector2D& v1, const Vector2D& v2) 
{
    return (v1.x * v2.x) + (v1.y * v2.y);
}

int main(){

    Vector2D v1(1, 2);
    Vector2D v2(3, 4);

    cout << "SUM: " << v1 + v2 << endl;
    cout << "DIFFERENCE: " << v1 - v2 << endl;
    cout << "SCALAR MULTIPLICATION OF v1: " << v1 * 5 << endl;
    cout << "DOT PRODUCT: " << dotProduct(v1, v2) << endl;

    return 0;
}