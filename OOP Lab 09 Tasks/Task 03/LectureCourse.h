#ifndef LECTURECOURSE_H
#define LECTURECOURSE_H

#include "Course.h"

class LectureCourse : public Course
{
private:
    double mids, finals;

public:
    LectureCourse(string code, int cr, double mid, double fin);

    void calculateGrade();
    void displayInfo();
};

#endif