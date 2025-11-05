# 第4课：项目结构组织

## 🎯 学习目标

- 学习规范的 C++ 项目目录结构
- 掌握 `target_include_directories` 命令
- 理解公共头文件（PUBLIC）和私有头文件（PRIVATE）
- 学会组织中型项目

## 📖 知识点

### 为什么需要规范的目录结构？

随着项目增大，把所有文件放在一个目录会导致：
- ❌ 难以查找文件
- ❌ 头文件和源文件混在一起
- ❌ 不清楚哪些文件属于库，哪些属于应用

**规范的结构可以：**
- ✅ 清晰的模块划分
- ✅ 方便团队协作
- ✅ 易于维护和扩展

### 标准 C++ 项目结构

```
project/
├── CMakeLists.txt          # 顶层 CMake 文件
├── include/                # 公共头文件
│   └── mylib/
│       └── mylib.h
├── src/                    # 源文件
│   ├── mylib.cpp
│   └── main.cpp
├── tests/                  # 测试文件（可选）
├── docs/                   # 文档（可选）
└── build/                  # 构建目录（不提交到版本控制）
```

## 💻 实践项目：学生管理系统

创建一个简单的学生管理库。

### 项目结构

```
lesson4-project-structure/
├── CMakeLists.txt
├── README.md
├── include/
│   └── student/
│       ├── Student.h
│       └── StudentManager.h
├── src/
│   ├── Student.cpp
│   ├── StudentManager.cpp
│   └── main.cpp
```

### 源代码

#### include/student/Student.h
```cpp
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
```

#### include/student/StudentManager.h
```cpp
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
```

#### src/Student.cpp
```cpp
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
```

#### src/StudentManager.cpp
```cpp
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
```

#### src/main.cpp
```cpp
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
```

## 📝 CMakeLists.txt 详解

```cmake
cmake_minimum_required(VERSION 3.10)
project(StudentSystem CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 收集库的源文件
set(LIB_SOURCES
    src/Student.cpp
    src/StudentManager.cpp
)

# 创建库
add_library(studentlib STATIC ${LIB_SOURCES})

# 为库指定 include 目录（PUBLIC 表示使用这个库的目标也能看到这个目录）
target_include_directories(studentlib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 创建可执行文件
add_executable(student_app src/main.cpp)

# 链接库（会自动继承库的 include 目录）
target_link_libraries(student_app studentlib)
```

### 关键命令详解

#### 1. CMAKE_CXX_STANDARD
```cmake
set(CMAKE_CXX_STANDARD 11)        # 使用 C++11 标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # 如果编译器不支持，报错
```

#### 2. target_include_directories
```cmake
target_include_directories(目标 访问级别 目录)
```

**访问级别：**
- `PUBLIC`: 目标自己用，链接它的目标也能用
- `PRIVATE`: 只有目标自己用
- `INTERFACE`: 自己不用，但链接它的目标能用

**示例：**
```cmake
# 公共头文件：所有使用 studentlib 的目标都能访问
target_include_directories(studentlib PUBLIC include)

# 私有头文件：只有 studentlib 自己能访问
target_include_directories(studentlib PRIVATE src/internal)
```

#### 3. CMAKE_CURRENT_SOURCE_DIR
- 当前 CMakeLists.txt 所在的目录
- 用于构建绝对路径，避免路径问题

## 🚀 动手操作

### 编译和运行

```powershell
# Windows
cd "d:\Obsidian Library\信息学奥赛笔记\300 语言\cmake\lesson4-project-structure"
mkdir build
cd build
cmake ..
cmake --build .
.\Debug\student_app.exe
```

```bash
# Linux
cd /mnt/d/Obsidian\ Library/信息学奥赛笔记/300\ 语言/cmake/lesson4-project-structure
mkdir build && cd build
cmake ..
make
./student_app
```

## 🔍 深入理解

### 为什么要分 include 和 src？

**include/**
- 存放头文件（.h）
- 对外暴露的接口
- 其他模块需要看到的内容

**src/**
- 存放实现文件（.cpp）
- 内部实现细节
- 不对外暴露

### PUBLIC vs PRIVATE vs INTERFACE

假设有三个目标：A（库）、B（使用A的库）、C（使用B的程序）

```
C → B → A
```

- `target_include_directories(A PUBLIC include/)`
  - A、B、C 都能访问 include/
  
- `target_include_directories(A PRIVATE include/)`
  - 只有 A 能访问 include/
  
- `target_include_directories(A INTERFACE include/)`
  - B、C 能访问，但 A 自己不能

**最佳实践：**
- 库的公共头文件目录用 `PUBLIC`
- 库的内部头文件目录用 `PRIVATE`
- 仅头文件库（header-only）用 `INTERFACE`

### 头文件路径问题

注意 include 语句的写法：

```cpp
// ✅ 推荐：相对于 include 目录
#include "student/Student.h"

// ❌ 不推荐：相对于当前文件
#include "../include/student/Student.h"
```

这样做的好处：
- 路径更清晰
- 移动文件不影响 include 语句
- 避免命名冲突（通过目录区分）

## 📝 练习题

### 练习 1：添加新类

在 `include/student/` 下创建 `Course.h`：
```cpp
class Course {
    int id;
    std::string name;
    // ...
};
```

在 `src/` 下创建 `Course.cpp` 实现，并更新 CMakeLists.txt。

### 练习 2：使用 PRIVATE

假设 Student.cpp 内部需要用到一些工具函数，创建：
- `src/internal/utils.h`
- `src/internal/utils.cpp`

然后在 CMakeLists.txt 中添加：
```cmake
target_include_directories(studentlib PRIVATE src)
```

### 练习 3：创建第二个库

创建一个 `mathlib`，结构为：
```
include/math/
    BasicMath.h
src/
    BasicMath.cpp
```

然后在 main.cpp 中同时使用 studentlib 和 mathlib。

### 练习 4：调试路径问题

故意写错 include 路径，观察编译错误信息，学习如何排查路径问题。

## ✅ 检查点

完成本课后，你应该能够回答：

- [ ] include 和 src 目录分别存放什么？
- [ ] `target_include_directories` 的三种访问级别是什么？
- [ ] 为什么使用 `#include "student/Student.h"` 而不是 `#include "Student.h"`？
- [ ] `CMAKE_CURRENT_SOURCE_DIR` 的作用是什么？

## 🎯 小结

本课核心要点：

1. **规范结构**：include/ 放头文件，src/ 放源文件
2. **包含目录**：`target_include_directories(目标 PUBLIC/PRIVATE 目录)`
3. **访问级别**：PUBLIC（传递）、PRIVATE（私有）、INTERFACE（接口）
4. **C++ 标准**：`set(CMAKE_CXX_STANDARD 11)`

## 下一步

准备好了吗？前往 **第5课：子目录和模块化** 学习如何管理大型项目！

---

**最佳实践：**
- ✅ 公共头文件用 PUBLIC
- ✅ 头文件放在有命名空间的子目录（如 student/）
- ✅ 使用相对于 include 的路径
- ✅ 保持目录结构简洁清晰
