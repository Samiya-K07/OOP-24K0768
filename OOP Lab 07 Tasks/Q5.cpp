//Samiya Khan
//24K-0768

#include<iostream>
#include<string>
using namespace std;

class Character{
protected:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;

public:
    Character(int id, string n, int l, int hp, string weapon) : characterID(id), name(n), level(l), healthPoints(hp), weaponType(weapon) {}

    virtual void attack() 
    {
        cout << name << " attacks!!" << endl;
    }

    virtual void defend() 
    {
        cout << name << " defends!!" << endl;
    }

    virtual void displayStats() 
    {
        cout << "Character ID: " << characterID << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health Points: " << healthPoints << endl;
        cout << "Weapon: " << weaponType << endl;
    }
};

class Warrior : public Character{
private:
    int armorStrength;
    int meleeDamage;

public:
    Warrior(int id, string n, int l, int hp, string weapon, int armor, int damage) : Character(id, n, l, hp, weapon), armorStrength(armor), meleeDamage(damage) {}

    void attack() 
    {
        cout << name << " strikes a " << weaponType << " strong " << meleeDamage << " damage!!" << endl;
    }
};

class Mage : public Character{
private:
    int manaPoints;
    int spellPower;

public:
    Mage(int id, string n, int l, int hp, string weapon, int mana, int power) : Character(id, n, l, hp, weapon), manaPoints(mana), spellPower(power) {}

    void defend() {

        cout << name << " uses magical barriers!!" << endl;
    }
};

class Archer : public Character{
private:
    int arrowCount;
    int rangedAccuracy;

public:
    Archer(int id, string n, int l, int hp, string weapon, int arrows, int accuracy) : Character(id, n, l, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}

    void attack() {
        cout << name << " shoots with " << rangedAccuracy << " sharp accuracy!!" << endl;
    }
};

class Rogue : public Character{
private:
    int stealthLevel;
    int agility;

public:
    Rogue(int id, string n, int l, int hp, string weapon, int stealth, int a) : Character(id, n, l, hp, weapon), stealthLevel(stealth), agility(a) {}

    void displayStats() 
    {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << endl;
        cout << "Agility: " << agility << endl;
    }
};

int main() {
    
    Warrior warrior1(101, "King Arthur", 15, 105, "Sword", 60, 20);
    Mage mage1(202, "Merlin", 13, 70, "Magical Staff", 100, 50);
    Archer archer1(303, "Artemis", 20, 85, "Bow", 30, 78);
    Rogue rogue1(404, "Apollo", 23, 78, "Hammer", 80, 85);

    warrior1.attack();
    mage1.defend();
    archer1.attack();
    rogue1.displayStats();
    
    return 0;
}