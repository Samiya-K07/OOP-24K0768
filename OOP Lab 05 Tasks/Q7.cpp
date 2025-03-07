//Samiya Khan
//24K-0768

#include<iostream>
#include<string>
using namespace std;

class Product{
public:
    int ID;
    string name;
    int quantity;

    Product(int id, string n, int q) : ID(id), name(n), quantity(q) {}

    void displayDetails() 
    {
        cout << "Product ID: " << ID << "\nName: " << name << "\nQuantity: " << quantity << endl;
    }
};

class Warehouse{
public:
    Product* inventory[100];
    int productCount;

    Warehouse() 
    {
        productCount = 0;
    }

    void addProduct(int i, string n, int q) 
    {
        inventory[productCount++] = new Product(i, n, q);
    }

    void sortProducts() 
    {
        for (int i = 0; i < productCount - 1; i++)
        {
            for (int j = 0; j < productCount - i - 1; j++)
            {
                if (inventory[j]->name > inventory[j + 1]->name) 
                {
                    swap(inventory[j], inventory[j + 1]);
                }
            }
        }
    }

    void searchID(int i) 
    {
        for (int i = 0; i < productCount; i++)
        {
            if (inventory[i]->ID == i) 
            {
                cout << "Product found successfully!!" << endl;
                inventory[i]->displayDetails();
                
                return;
            }
        }
        cout << "Product with ID " << i << " not found!!" << endl;
    }

    void displayDetails() 
    {
        cout << "Inventory List:\n" << endl;
        
        for (int i = 0; i < productCount; i++)
        {
            inventory[i]->displayDetails();
        }
    }

    ~Warehouse() 
    {
        for (int i = 0; i < productCount; i++)
        {
            delete inventory[i];
        }
    }
};

int main() {
    
    Warehouse warehouse1;
    warehouse1.addProduct(200, "Drawer", 10);
    warehouse1.addProduct(201, "IPAD", 6);
    warehouse1.addProduct(202, "Chair", 30);
    warehouse1.addProduct(203, "Table", 15);

    cout << "Before Sorting: " << endl;
    warehouse1.displayDetails();

    warehouse1.sortProducts();
    
    cout << "After sorting alphabetically: " << endl;
    warehouse1.displayDetails();

    int ID;
    
    cout << "Enter Product ID you want to search: ";
    cin >> ID;
    
    warehouse1.searchID(ID);

    return 0;
}