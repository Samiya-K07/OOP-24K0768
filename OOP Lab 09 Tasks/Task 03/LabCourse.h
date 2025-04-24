#ifndef LABCOURSE_H
#define LABCOURSE_H

#include "Course.h"

class LabCourse : public Course
{
private:
    double labTasks, project;

public:
    LabCourse(string code, int cr, double lab, double proj);

    void calculateGrade();
    void displayInfo();
};

#endif