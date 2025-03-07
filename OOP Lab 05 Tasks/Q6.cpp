//Samiya Khan
//24K-0768

#include<iostream>
#include<string>
using namespace std;

class Level{
private:
    string type;

public:
    Level() {}
    Level(string t) : type(t) {}
    
    void displayDetails() 
    {
        cout << "Level: " << type << endl;
    }
};

class VideoGame{
private:
    string title;
    string genre;
    Level levels[10];
    int levelCount;

public:
    VideoGame(string t, string g) : title(t), genre(g), levelCount(0) {}
    
    void addLevel(string levelType) 
    {
        if (levelCount < 10) 
        {
            levels[levelCount++] = Level(levelType);
        } 
        
        else 
        {
            cout << "Limit reached!! More levels cannot be added!!" << endl;
        }
    }
    
    void displayDetails() 
    {
        cout << "Game: " << title << "\nGenre: " << genre << endl;
        cout << "Levels: " << endl;
        
        for (int i = 0; i < levelCount; i++)
        {
            levels[i].displayDetails();
        }
    }
};

int main() {
    
    VideoGame game1("Tekken", "Combat Game");
    game1.addLevel("Easy");
    game1.addLevel("Difficult");
    game1.addLevel("Intermediate");
    
    game1.displayDetails();
    
    return 0;
}