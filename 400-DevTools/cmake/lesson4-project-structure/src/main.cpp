#include <iostream>
#include "student/Student.h"
#include "student/StudentManager.h"

int main() {
    StudentManager manager;
    
    // 添加学生
    manager.addStudent(Student(1, "张三", 85.5));
    manager.addStudent(Student(2, "李四", 92.0));
    manager.addStudent(Student(3, "王五", 78.5));
    
    // 显示所有学生
    manager.printAll();
    
    // 统计信息
    std::cout << "\n学生总数: " << manager.getStudentCount() << std::endl;
    std::cout << "平均成绩: " << manager.getAverageScore() << std::endl;
    
    return 0;
}
