//Samiya Khan
//24K-0768

#include<iostream>
#include<string>
using namespace std;

class Product{
protected:
    int productID;
    string productName;
    double price;
    int stockQuantity;

public:
    Product(int id, string name, double p, int stock) : productID(id), productName(name), price(p), stockQuantity(stock) {}
    
    virtual void applyDiscount(double percent) 
    {
        price -= price * (percent / 100);
    }
    
    virtual double calculateTotalPrice(int quantity) 
    {
        return (price * quantity);
    }
    
    virtual void displayProductInfo() 
    {
        cout << "Product ID: " << productID << "\nName: " << productName << "\nPrice: " << price << "\nStock Quantity: " << stockQuantity << endl;
    }
    
};

class Electronics : public Product{
private:
    int warrantyPeriod;
    string brand;

public:
    Electronics(int id, string name, double p, int stock, int warranty, string b) : Product(id, name, p, stock), warrantyPeriod(warranty), brand(b) {}
    
    void displayProductInfo() 
    {
        Product::displayProductInfo();
        cout << "Brand: " << brand << "\nWarranty: " << warrantyPeriod << endl;
    }
};

class Clothing : public Product{
private:
    string size;
    string color;
    string fabricMaterial;

public:
    Clothing(int id, string name, double p, int stock, string s, string c, string fabric) : Product(id, name, p, stock), size(s), color(c), fabricMaterial(fabric) {}
    
    void applyDiscount(double percentage) 
    {
        if (percentage > 20) 
        {
            percentage = 20;
        }
        
        Product::applyDiscount(percentage);
    }
};

class FoodItem : public Product{
private:
    string expirationDate;
    int calories;

public:
    FoodItem(int id, string name, double p, int stock, string expiration, int c) : Product(id, name, p, stock), expirationDate(expiration), calories(c) {}
    
    double calculateTotalPrice(int quantity) 
    {
        double total = Product::calculateTotalPrice(quantity);
        if (quantity > 10) 
        {
            total *= 0.9;
        }
        
        return total;
    }
};

class Book : public Product{
private:
    string author;
    string genre;

public:
    Book(int id, string name, double p, int stock, string a, string g) : Product(id, name, p, stock), author(a), genre(g) {}
    
    void displayProductInfo() 
    {
        Product::displayProductInfo();
        cout << "Author: " << author << "\nGenre: " << genre << endl;
    }
};

int main() {
    Electronics tablet1(10, "Apple Tablet", 47000, 06, 4, "Apple");
    Clothing shirt1(24, "Cotton Shirt", 800, 35, "Small", "Beige", "Cotton");
    FoodItem bread1(44, "Fresh Bread", 10, 40, "2025-08-12", 80);
    Book novel(68, "Fantasy Novel", 1400, 15, "Leigh Bardugo", "Fantasy");

    tablet1.displayProductInfo();
    shirt1.applyDiscount(25);
    cout << "Total Price for bread: " << bread1.calculateTotalPrice(6) << endl;
    novel.displayProductInfo();
    
    return 0;
}