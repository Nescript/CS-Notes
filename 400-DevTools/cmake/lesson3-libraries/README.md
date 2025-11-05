# 第3课：静态库和动态库

## 🎯 学习目标

- 理解库（Library）的概念和作用
- 学会创建静态库（.a / .lib）和动态库（.so / .dll）
- 掌握 `add_library` 和 `target_link_libraries` 命令
- 理解静态链接和动态链接的区别

## 📖 知识点

### 什么是库？

**库（Library）** 是预先编译好的代码集合，可以被其他程序使用：
- **复用代码**：写一次，多处使用
- **模块化**：隐藏实现细节，只暴露接口
- **发布方便**：可以分发给其他人使用

### 静态库 vs 动态库

| 特性 | 静态库 | 动态库 |
|------|--------|--------|
| **文件扩展名** | Linux: `.a`<br>Windows: `.lib` | Linux: `.so`<br>Windows: `.dll` |
| **链接时机** | 编译时链接到可执行文件 | 运行时加载 |
| **可执行文件大小** | 大（包含库代码） | 小（不包含库代码） |
| **更新库** | 需要重新编译程序 | 只需替换库文件 |
| **依赖** | 无外部依赖 | 需要库文件存在 |

### 链接过程

```
静态链接: 源码 → 编译 → [库代码嵌入] → 大可执行文件
动态链接: 源码 → 编译 → 可执行文件 + 库文件（运行时加载）
```

## 💻 实践项目：数学库

创建一个数学库，包含基本数学运算。

### 项目结构

```
lesson3-libraries/
├── CMakeLists.txt
├── main.cpp              # 主程序
├── mathlib.h             # 库的头文件
├── mathlib.cpp           # 库的实现
└── README.md
```

### 源代码

#### mathlib.h
```cpp
#ifndef MATHLIB_H
#define MATHLIB_H

namespace MathLib {
    double square(double x);
    double cube(double x);
    int factorial(int n);
    bool isPrime(int n);
}

#endif
```

#### mathlib.cpp
```cpp
#include "mathlib.h"

namespace MathLib {
    double square(double x) {
        return x * x;
    }

    double cube(double x) {
        return x * x * x;
    }

    int factorial(int n) {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }

    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }
}
```

#### main.cpp
```cpp
#include <iostream>
#include "mathlib.h"

int main() {
    std::cout << "=== 使用 MathLib 静态/动态库 ===" << std::endl;
    
    std::cout << "5 的平方: " << MathLib::square(5) << std::endl;
    std::cout << "3 的立方: " << MathLib::cube(3) << std::endl;
    std::cout << "5 的阶乘: " << MathLib::factorial(5) << std::endl;
    std::cout << "17 是质数吗? " << (MathLib::isPrime(17) ? "是" : "否") << std::endl;
    
    return 0;
}
```

## 📝 CMakeLists.txt 详解

### 版本1：创建静态库

```cmake
cmake_minimum_required(VERSION 3.10)
project(MathLibProject CXX)

# 创建静态库
add_library(mathlib STATIC mathlib.cpp)

# 创建可执行文件
add_executable(app main.cpp)

# 链接库到可执行文件
target_link_libraries(app mathlib)
```

**关键命令解释：**

1. `add_library(mathlib STATIC mathlib.cpp)`
   - 创建名为 `mathlib` 的静态库
   - `STATIC` 表示静态库
   - 只需列出 .cpp 文件，头文件会自动处理

2. `target_link_libraries(app mathlib)`
   - 将 `mathlib` 链接到 `app`
   - 这样 `app` 就能使用库中的函数

### 版本2：创建动态库

```cmake
cmake_minimum_required(VERSION 3.10)
project(MathLibProject CXX)

# 创建动态库
add_library(mathlib SHARED mathlib.cpp)

# 创建可执行文件
add_executable(app main.cpp)

# 链接库
target_link_libraries(app mathlib)
```

只需把 `STATIC` 改为 `SHARED`！

### 版本3：同时创建两种库

```cmake
cmake_minimum_required(VERSION 3.10)
project(MathLibProject CXX)

# 创建静态库
add_library(mathlib_static STATIC mathlib.cpp)

# 创建动态库
add_library(mathlib_shared SHARED mathlib.cpp)

# 可执行文件（使用静态库）
add_executable(app_static main.cpp)
target_link_libraries(app_static mathlib_static)

# 可执行文件（使用动态库）
add_executable(app_shared main.cpp)
target_link_libraries(app_shared mathlib_shared)
```

## 🚀 动手操作

### Windows 下编译静态库

```powershell
cd "d:\Obsidian Library\信息学奥赛笔记\300 语言\cmake\lesson3-libraries"
mkdir build
cd build
cmake ..
cmake --build .

# 运行程序
.\Debug\app.exe

# 查看生成的文件
dir Debug
# 你会看到 mathlib.lib (静态库) 和 app.exe
```

### Linux 下编译

```bash
cd /mnt/d/Obsidian\ Library/信息学奥赛笔记/300\ 语言/cmake/lesson3-libraries
mkdir build && cd build
cmake ..
make

# 运行
./app

# 查看生成的文件
ls -lh
# libmathlib.a (静态库) 和 app
```

### 切换到动态库

修改 CMakeLists.txt，把 `STATIC` 改为 `SHARED`，然后：

```powershell
# Windows
cd build
cmake ..
cmake --build .
dir Debug  # 你会看到 mathlib.dll
```

```bash
# Linux
cd build
cmake ..
make
ls -lh  # libmathlib.so
```

## 🔍 深入理解

### 文件大小对比

编译后对比文件大小：

```bash
# 静态链接的程序（较大）
app_static: 约 50-100 KB

# 动态链接的程序（较小）
app_shared: 约 20-30 KB
libmathlib.so: 约 10-20 KB
```

### Windows 下的动态库

Windows 动态库需要在运行时找到 .dll：
- 放在可执行文件同目录
- 放在系统 PATH 路径
- 否则会报错："找不到 xxx.dll"

### target_link_libraries 的作用

不仅仅是链接，还会：
- 自动添加库的头文件路径
- 处理传递依赖（A 依赖 B，B 依赖 C）
- 设置链接顺序

## 📝 练习题

### 练习 1：测试静态库和动态库

分别编译静态库和动态库版本，对比：
1. 可执行文件大小
2. 构建输出信息
3. 运行时的区别

### 练习 2：添加更多函数

在 `mathlib.h` 和 `mathlib.cpp` 中添加：
```cpp
double power(double base, int exp);  // 幂运算
int gcd(int a, int b);               // 最大公约数
```

无需修改 CMakeLists.txt！

### 练习 3：创建另一个库

创建 `stringlib.h` 和 `stringlib.cpp`，实现字符串处理函数：
```cpp
std::string toUpper(const std::string& s);
std::string reverse(const std::string& s);
```

然后在 CMakeLists.txt 中创建库并链接。

### 练习 4：多个库

修改 main.cpp 同时使用 mathlib 和 stringlib：
```cmake
add_library(mathlib STATIC mathlib.cpp)
add_library(stringlib STATIC stringlib.cpp)
add_executable(app main.cpp)
target_link_libraries(app mathlib stringlib)
```

## ✅ 检查点

完成本课后，你应该能够回答：

- [ ] 静态库和动态库的主要区别是什么？
- [ ] `add_library()` 的第二个参数可以是哪些值？
- [ ] `target_link_libraries()` 的两个参数分别是什么？
- [ ] 为什么头文件不需要添加到 `add_library()`？
- [ ] Windows 的 .dll 和 Linux 的 .so 是对应的吗？

## 🎯 小结

本课核心要点：

1. **创建库**：`add_library(库名 STATIC/SHARED 源文件)`
2. **链接库**：`target_link_libraries(目标 库名)`
3. **静态库**：编译时嵌入，文件大，无依赖
4. **动态库**：运行时加载，文件小，需要 .dll/.so

## 下一步

准备好了吗？前往 **第4课：项目结构组织** 学习规范的目录结构！

---

**提示：** 在实际项目中，通常使用静态库用于内部模块，动态库用于对外发布。
