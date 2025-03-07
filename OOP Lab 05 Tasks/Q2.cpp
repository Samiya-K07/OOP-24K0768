//Samiya Khan
//24K-0768

#include<iostream>
#include<string>
using namespace std;

class Student{
public:
    int ID;
    string name;
    int* scores;
    int scoreCount;

    Student(int i, string n, int* s, int count) 
    {
        ID = i;
        name = n;
        scoreCount = count;
        scores = new int[scoreCount];

        for (int i = 0; i < scoreCount; i++)
        {
            scores[i] = s[i];
        }
    }

    Student(const Student &obj) 
    {
        ID = obj.ID;
        name = obj.name;
        scoreCount = obj.scoreCount;
        scores = new int[scoreCount];

        for (int i = 0; i < scoreCount; i++)
        {
            scores[i] = obj.scores[i];
        }
    }

    void displayDetails() 
    {
        cout << "Student ID: " << ID << "\nStudent Name: " << name << "\nScores: ";
        
        for (int i = 0; i < scoreCount; i++) 
        {
            cout << scores[i] << " ";
        }
        cout << endl;
    }

    ~Student() 
    {
        delete[] scores;
    }
};

int main() {
    
    int score1[] = {65, 87, 70};
    Student s1(30, "Samiya", score1, 3);

    cout << "Original Student Record: " << endl;
    s1.displayDetails();

    Student s2(s1);
    cout << "Duplicate Record for Verification: " << endl;
    s2.displayDetails();

    return 0;
}