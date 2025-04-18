#include <iostream>
using namespace std;

class FoodItem
{
protected:
    string itemName;
    double cost;

public:
    FoodItem(string name, double c) : itemName(name), cost(c) {}

    virtual void displayInfo() const = 0;
    virtual void makeDish() const = 0;

    virtual ~FoodItem() {}
};

class Starter : public FoodItem
{
public:
    Starter(string name, double c) : FoodItem(name, c) {}

    void displayInfo() const override
    {
        cout << "Starter Dish: " << itemName << " | Cost: $" << cost << "\n";
    }

    void makeDish() const override
    {
        cout << "Creating starter: " << itemName << "\n";
        cout << " - Preparing ingredients\n - Quick sauté or bake\n - Serving in small portions\n\n";
    }
};

class Entree : public FoodItem
{
public:
    Entree(string name, double c) : FoodItem(name, c) {}

    void displayInfo() const override
    {
        cout << "Entree Dish: " << itemName << " | Cost: $" << cost << "\n";
    }

    void makeDish() const override
    {
        cout << "Cooking entree: " << itemName << "\n";
        cout << " - Cooking main ingredients\n - Flavoring with spices\n - Presentation and sides\n\n";
    }
};

int main()
{
    const int ITEM_COUNT = 2;
    FoodItem *menu[ITEM_COUNT];

    menu[0] = new Starter("Garlic Bread", 3.75);
    menu[1] = new Entree("Beef Steak", 14.90);

    for (int i = 0; i < ITEM_COUNT; ++i)
    {
        menu[i]->displayInfo();
        menu[i]->makeDish();
    }

    for (int i = 0; i < ITEM_COUNT; ++i)
    {
        delete menu[i];
    }

    return 0;
}
