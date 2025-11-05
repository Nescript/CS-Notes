#include "student/StudentManager.h"
#include <iostream>
#include <numeric>

void StudentManager::addStudent(const Student& student) {
    students.push_back(student);
}

void StudentManager::printAll() const {
    std::cout << "\n=== 学生列表 ===" << std::endl;
    for (const auto& student : students) {
        student.print();
    }
}

double StudentManager::getAverageScore() const {
    if (students.empty()) return 0.0;
    double sum = 0;
    for (const auto& student : students) {
        sum += student.getScore();
    }
    return sum / students.size();
}

int StudentManager::getStudentCount() const {
    return students.size();
}
