// Samiya Khan
// 24K-0768

#include <iostream>
#include <exception>
using namespace std;

class NegativeStockException : public exception
{
};

class OverCapacityException : public exception
{
};

template <typename T>
class InventoryItem
{
private:
    T currentStock;
    T maxStock;

public:
    InventoryItem(T limit) : currentStock(0), maxStock(limit) {}

    void setStock(T qty)
    {
        if (qty < 0)
        {
            throw NegativeStockException();
        }

        else if (qty > maxStock)
        {
            throw OverCapacityException();
        }
        
        currentStock = qty;
        cout << "Stock set to: " << currentStock << endl;
    }
};

int main()
{
    InventoryItem<int> item(100);

    try
    {
        cout << "Attempting to set stock to -5..." << endl;
        item.setStock(-5);
    }
    catch (const NegativeStockException &ex)
    {
        cout << "Caught NegativeStockException" << endl;
        cout << "what(): " << ex.what() << endl;
    }

    try
    {
        cout << "Attempting to set stock to 120 (max 100)..." << endl;
        item.setStock(120);
    }
    catch (const OverCapacityException &ex)
    {
        cout << "Caught OverCapacityException" << endl;
        cout << "what(): " << ex.what() << endl;
    }

    return 0;
}
