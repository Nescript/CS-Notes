# 第2课：多文件项目

## 🎯 学习目标

- 学会管理多个 C++ 源文件和头文件
- 理解编译和链接的区别
- 掌握 CMake 中管理文件列表的方法
- 学习使用变量简化 CMakeLists.txt

## 📖 知识点

### 为什么需要多文件？

在实际项目中，我们会把代码分成多个文件：
- **模块化**：每个文件负责一个功能
- **可维护性**：容易查找和修改代码
- **复用性**：头文件可以被多个源文件包含
- **编译效率**：修改一个文件只需重新编译它

### 编译过程回顾

```
源文件(.cpp) → [编译] → 目标文件(.o/.obj) → [链接] → 可执行文件
```

CMake 会自动处理这些步骤，我们只需告诉它所有的源文件。

## 💻 实践项目：计算器程序

我们将创建一个简单的计算器，包含多个文件。

### 项目结构

```
lesson2-multiple-files/
├── CMakeLists.txt
├── main.cpp           # 主程序
├── calculator.h       # 计算器头文件
├── calculator.cpp     # 计算器实现
└── README.md
```

### 源代码

#### calculator.h - 头文件
```cpp
#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
};

#endif // CALCULATOR_H
```

#### calculator.cpp - 实现文件
```cpp
#include "calculator.h"
#include <stdexcept>

double Calculator::add(double a, double b) {
    return a + b;
}

double Calculator::subtract(double a, double b) {
    return a - b;
}

double Calculator::multiply(double a, double b) {
    return a * b;
}

double Calculator::divide(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("除数不能为零！");
    }
    return a / b;
}
```

#### main.cpp - 主程序
```cpp
#include <iostream>
#include "calculator.h"

int main() {
    Calculator calc;
    
    std::cout << "=== CMake 多文件项目示例 ===" << std::endl;
    std::cout << "10 + 5 = " << calc.add(10, 5) << std::endl;
    std::cout << "10 - 5 = " << calc.subtract(10, 5) << std::endl;
    std::cout << "10 * 5 = " << calc.multiply(10, 5) << std::endl;
    std::cout << "10 / 5 = " << calc.divide(10, 5) << std::endl;
    
    try {
        calc.divide(10, 0);
    } catch (const std::exception& e) {
        std::cout << "错误: " << e.what() << std::endl;
    }
    
    return 0;
}
```

### CMakeLists.txt（方法一：直接列举）

```cmake
cmake_minimum_required(VERSION 3.10)
project(Calculator CXX)

# 方法一：直接列出所有源文件
add_executable(calculator 
    main.cpp
    calculator.cpp
)
```

**注意：** 头文件 `.h` 不需要写在这里！CMake 会自动处理 `#include`。

### CMakeLists.txt（方法二：使用变量）

```cmake
cmake_minimum_required(VERSION 3.10)
project(Calculator CXX)

# 方法二：使用变量管理源文件
set(SOURCES
    main.cpp
    calculator.cpp
)

add_executable(calculator ${SOURCES})
```

### CMakeLists.txt（方法三：自动收集，慎用！）

```cmake
cmake_minimum_required(VERSION 3.10)
project(Calculator CXX)

# 方法三：自动收集所有 .cpp 文件（不推荐用于大型项目）
file(GLOB SOURCES "*.cpp")

add_executable(calculator ${SOURCES})
```

⚠️ **警告：** `file(GLOB)` 在大型项目中不推荐，因为：
- 添加新文件后需要重新运行 CMake
- 可能意外包含不需要的文件

## 🚀 动手操作

### 在 Windows PowerShell 中

```powershell
cd "d:\Obsidian Library\信息学奥赛笔记\300 语言\cmake\lesson2-multiple-files"
mkdir build
cd build
cmake ..
cmake --build .
.\Debug\calculator.exe
```

### 在 WSL Ubuntu 中

```bash
cd /mnt/d/Obsidian\ Library/信息学奥赛笔记/300\ 语言/cmake/lesson2-multiple-files
mkdir build && cd build
cmake ..
make
./calculator
```

## 🔍 深入理解

### 为什么头文件不需要写在 CMakeLists.txt？

- CMake 追踪的是 **编译单元**（.cpp 文件）
- 头文件通过 `#include` 被自动包含
- 编译器会自动处理头文件依赖

### set 命令详解

```cmake
set(变量名 值1 值2 值3 ...)
```

- 创建或修改变量
- `${变量名}` 用于引用变量的值
- 变量可以包含多个值（列表）

### 编译输出解读

```
[ 33%] Building CXX object CMakeFiles/calculator.dir/main.cpp.o
[ 66%] Building CXX object CMakeFiles/calculator.dir/calculator.cpp.o
[100%] Linking CXX executable calculator
```

- 33%, 66%：分别编译两个 .cpp 文件
- 100%：链接成可执行文件

## 📝 练习题

### 练习 1：添加新功能
在 `calculator.h` 和 `calculator.cpp` 中添加一个 `power(double base, double exp)` 方法，计算幂运算。

提示：
```cpp
// calculator.h
double power(double base, double exp);

// calculator.cpp
#include <cmath>
double Calculator::power(double base, double exp) {
    return std::pow(base, exp);
}
```

不需要修改 CMakeLists.txt！重新编译即可。

### 练习 2：再添加一个文件
创建 `utils.h` 和 `utils.cpp`，实现一个 `printBanner()` 函数打印欢迎信息。
记得在 CMakeLists.txt 中添加 `utils.cpp`！

### 练习 3：对比三种方法
分别用三种方法编写 CMakeLists.txt，观察效果有何不同。

### 练习 4：故意制造错误
尝试以下操作，理解错误信息：
- 在 CMakeLists.txt 中删除 `calculator.cpp`，看会报什么错
- 在 main.cpp 中包含一个不存在的头文件

## ✅ 检查点

完成本课后，你应该能够回答：

- [ ] 为什么头文件不需要添加到 `add_executable`？
- [ ] `set()` 命令的作用是什么？
- [ ] `${SOURCES}` 中的 `${}` 是做什么用的？
- [ ] 修改头文件后，需要重新运行 `cmake ..` 吗？（不需要，只需 `cmake --build .`）

## 🎯 小结

本课要点：

1. **多文件管理**：用 `add_executable()` 列出所有 .cpp 文件
2. **变量使用**：`set()` 定义变量，`${}` 引用变量
3. **头文件处理**：自动处理，无需在 CMakeLists.txt 中列出
4. **推荐做法**：明确列出源文件，避免 `file(GLOB)`

## 下一步

做好准备了吗？前往 **第3课：静态库和动态库** 学习如何创建和使用库！

---

**最佳实践建议：**
- ✅ 明确列出所有源文件
- ✅ 使用变量组织文件列表
- ✅ 保持 CMakeLists.txt 简洁易读
- ❌ 不要在大型项目中使用 `file(GLOB)`
