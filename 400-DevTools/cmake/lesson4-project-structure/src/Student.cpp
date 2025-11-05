#include "student/Student.h"
#include <iostream>

Student::Student(int id, const std::string& name, double score)
    : id(id), name(name), score(score) {}

void Student::setScore(double newScore) {
    score = newScore;
}

void Student::print() const {
    std::cout << "ID: " << id 
              << ", 姓名: " << name 
              << ", 成绩: " << score << std::endl;
}
