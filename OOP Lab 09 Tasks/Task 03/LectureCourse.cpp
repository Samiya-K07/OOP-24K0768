#include "LectureCourse.h"
#include <iostream>
using namespace std;

LectureCourse::LectureCourse(string code, int cr, double mid, double fin) : Course(code, cr), mids(mid), finals(fin) {}

void LectureCourse::calculateGrade()
{
    double finalGrade = (mids * 0.4) + (finals * 0.6);
    cout << "Final Grade (Lecture): " << finalGrade << endl;
}

void LectureCourse::displayInfo()
{
    cout << "Lecture Course: " << courseCode << "\nCredits: " << credits << endl;
}