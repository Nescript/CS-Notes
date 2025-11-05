#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    int id;
    std::string name;
    double score;

public:
    Student(int id, const std::string& name, double score);
    
    int getId() const { return id; }
    std::string getName() const { return name; }
    double getScore() const { return score; }
    
    void setScore(double newScore);
    void print() const;
};

#endif
