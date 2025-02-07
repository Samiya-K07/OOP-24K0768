//Samiya Khan
//24K-0768
//Task 09

#include <iostream>
#include <string>
using namespace std;

struct ProductDetails
{
    int productID;
    int quantity;
    double price;
    string name;
};

int main() {
    
    int products_no;
    double value = 0;

    cout << "Enter the number of products: ";
    cin >> products_no;

    ProductDetails* inventory = new ProductDetails[products_no];

    for (int i = 0; i < products_no; i++) 
    {
        cout << "Enter product details of product " << i+1 << " :" << endl;
        
        cout << "Product ID: ";
        cin >> inventory[i].productID;
        
        cout << "Name of Product: ";
        cin >> inventory[i].name;
        
        cout << "Quantity: ";
        cin >> inventory[i].quantity;
        
        cout << "Price: ";
        cin >> inventory[i].price;

        value += (inventory[i].quantity * inventory[i].price);
    }

    cout << "The entire value of inventory: " << value << endl;

    delete[] inventory;

    return 0;
}