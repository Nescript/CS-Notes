#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include <vector>
#include "Student.h"

class StudentManager {
private:
    std::vector<Student> students;

public:
    void addStudent(const Student& student);
    void printAll() const;
    double getAverageScore() const;
    int getStudentCount() const;
};

#endif
