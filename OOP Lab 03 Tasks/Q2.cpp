//Samiya Khan
//24K-0768
//Task 02

#include <iostream>
#include <string>
using namespace std;

class FitnessTracker{

private:
    string userName;
    int dailyStepGoal;
    int stepsTaken;
    double caloriesBurned;

public:
    FitnessTracker(string name, int goal)
    {
        userName = name;
        dailyStepGoal = goal;
        stepsTaken = 0;
        caloriesBurned = 0.0;
    }

    void log_steps(int steps)
    {
        if (steps > 0)
        {
            stepsTaken += steps;
            caloriesBurned += steps * 0.02;
            
            cout << steps << " steps logged successfully!!" << endl;
        } 
        
        else
        {
            cout << "Step count invalid!!" << endl;
        }
    }

    void calculate_calories(int steps)
    {
        caloriesBurned += steps * 0.02;
        cout << caloriesBurned << " calories have been burned succesfullly!!" << endl;
    }

    bool is_goal()
    {
        return stepsTaken >= dailyStepGoal;
    }

    void display_progress()
    {
        cout << "Fitness Progress\n" << endl;
        cout << "User = " << userName << endl;
        cout << "Daily Step Goal = " << dailyStepGoal << " steps" << endl;
        cout << "Steps Taken = " << stepsTaken << endl;
        cout << "Calories Burned = " << caloriesBurned << " kcal" << endl;
        
        if (is_goal())
        {
            cout << "Congratulation!! You've accomplished your set goal!!" << endl;
        } 
        
        else
        {
            cout << "Oops!! Looks like you need to work hard!!" << endl;
        }
        cout << endl;
    }
};

int main() {
    
    FitnessTracker laiba("Laiba", 8000);

    laiba.log_steps(6000);
    laiba.calculate_calories(6000);
    laiba.display_progress();
    laiba.log_steps(10000);
    laiba.calculate_calories(10000);
    laiba.display_progress();

    return 0;
}