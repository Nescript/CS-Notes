# 第5课：子目录和模块化

## 🎯 学习目标

- 理解大型项目的模块化组织
- 掌握 `add_subdirectory` 命令
- 学会编写多层级的 CMakeLists.txt
- 理解父子 CMakeLists.txt 之间的关系

## 📖 知识点

### 为什么需要子目录？

随着项目规模增大，单个 CMakeLists.txt 会变得：
- ❌ 过长、难以维护
- ❌ 模块职责不清
- ❌ 多人协作时容易冲突

**使用子目录的好处：**
- ✅ 每个模块有自己的 CMakeLists.txt
- ✅ 职责清晰，易于理解
- ✅ 可以独立编译和测试
- ✅ 更好的代码组织

### add_subdirectory 的作用

```cmake
add_subdirectory(子目录路径)
```

- CMake 会进入子目录查找 CMakeLists.txt
- 子目录中定义的目标在父目录可见
- 子目录继承父目录的一些设置

## 💻 实践项目：图书管理系统

创建一个包含多个模块的图书管理系统。

### 项目结构

```
lesson5-subdirectories/
├── CMakeLists.txt              # 顶层 CMake
├── README.md
├── libs/                       # 库目录
│   ├── book/                   # 图书模块
│   │   ├── CMakeLists.txt
│   │   ├── include/
│   │   │   └── book/
│   │   │       └── Book.h
│   │   └── src/
│   │       └── Book.cpp
│   └── utils/                  # 工具模块
│       ├── CMakeLists.txt
│       ├── include/
│       │   └── utils/
│       │       └── StringUtils.h
│       └── src/
│           └── StringUtils.cpp
└── app/                        # 应用程序
    ├── CMakeLists.txt
    └── main.cpp
```

### 源代码

#### libs/book/include/book/Book.h
```cpp
#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    int id;
    std::string title;
    std::string author;
    double price;

public:
    Book(int id, const std::string& title, 
         const std::string& author, double price);
    
    int getId() const { return id; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    double getPrice() const { return price; }
    
    void print() const;
};

#endif
```

#### libs/book/src/Book.cpp
```cpp
#include "book/Book.h"
#include <iostream>
#include <iomanip>

Book::Book(int id, const std::string& title, 
           const std::string& author, double price)
    : id(id), title(title), author(author), price(price) {}

void Book::print() const {
    std::cout << std::left << std::setw(5) << id
              << std::setw(30) << title
              << std::setw(20) << author
              << std::fixed << std::setprecision(2) << price << std::endl;
}
```

#### libs/book/CMakeLists.txt
```cmake
# 图书模块的 CMakeLists.txt

# 收集源文件
set(BOOK_SOURCES
    src/Book.cpp
)

# 创建库
add_library(booklib STATIC ${BOOK_SOURCES})

# 指定 include 目录
target_include_directories(booklib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 可选：设置库的别名，便于使用
add_library(Book::lib ALIAS booklib)
```

#### libs/utils/include/utils/StringUtils.h
```cpp
#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>

namespace StringUtils {
    std::string toUpper(const std::string& str);
    std::string toLower(const std::string& str);
    std::string trim(const std::string& str);
}

#endif
```

#### libs/utils/src/StringUtils.cpp
```cpp
#include "utils/StringUtils.h"
#include <algorithm>
#include <cctype>

namespace StringUtils {
    std::string toUpper(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), 
                      result.begin(), ::toupper);
        return result;
    }

    std::string toLower(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), 
                      result.begin(), ::tolower);
        return result;
    }

    std::string trim(const std::string& str) {
        size_t start = str.find_first_not_of(" \t\n\r");
        size_t end = str.find_last_not_of(" \t\n\r");
        if (start == std::string::npos) return "";
        return str.substr(start, end - start + 1);
    }
}
```

#### libs/utils/CMakeLists.txt
```cmake
# 工具模块的 CMakeLists.txt

set(UTILS_SOURCES
    src/StringUtils.cpp
)

add_library(utilslib STATIC ${UTILS_SOURCES})

target_include_directories(utilslib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(Utils::lib ALIAS utilslib)
```

#### app/main.cpp
```cpp
#include <iostream>
#include "book/Book.h"
#include "utils/StringUtils.h"

int main() {
    std::cout << "=== 图书管理系统 ===" << std::endl;
    std::cout << std::endl;
    
    // 创建图书
    Book book1(1, "C++ Primer", "Stanley B. Lippman", 128.00);
    Book book2(2, "Effective C++", "Scott Meyers", 79.00);
    Book book3(3, "The C++ Programming Language", "Bjarne Stroustrup", 139.00);
    
    // 打印图书列表
    std::cout << "图书列表：" << std::endl;
    book1.print();
    book2.print();
    book3.print();
    std::cout << std::endl;
    
    // 使用工具函数
    std::string title = "c++ primer";
    std::cout << "原标题: " << title << std::endl;
    std::cout << "大写: " << StringUtils::toUpper(title) << std::endl;
    std::cout << "小写: " << StringUtils::toLower("EFFECTIVE C++") << std::endl;
    
    return 0;
}
```

#### app/CMakeLists.txt
```cmake
# 应用程序的 CMakeLists.txt

add_executable(bookapp main.cpp)

# 链接两个库
target_link_libraries(bookapp
    booklib
    utilslib
)
```

#### 顶层 CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 3.10)
project(BookManagementSystem CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加库子目录
add_subdirectory(libs/book)
add_subdirectory(libs/utils)

# 添加应用程序子目录
add_subdirectory(app)

# 可选：打印消息
message(STATUS "配置图书管理系统完成")
```

## 🚀 动手操作

### 编译整个项目

```powershell
# Windows
cd "d:\Obsidian Library\信息学奥赛笔记\300 语言\cmake\lesson5-subdirectories"
mkdir build
cd build
cmake ..
cmake --build .
.\app\Debug\bookapp.exe
```

```bash
# Linux
cd /mnt/d/Obsidian\ Library/信息学奥赛笔记/300\ 语言/cmake/lesson5-subdirectories
mkdir build && cd build
cmake ..
make
./app/bookapp
```

## 🔍 深入理解

### CMake 的执行顺序

1. 读取顶层 CMakeLists.txt
2. 遇到 `add_subdirectory(libs/book)`，进入该目录
3. 执行 libs/book/CMakeLists.txt
4. 返回顶层，继续执行
5. 依次处理所有子目录

### 变量作用域

**父目录 → 子目录：** 子目录可以访问父目录的变量

```cmake
# 父 CMakeLists.txt
set(MY_VAR "Hello")
add_subdirectory(subdir)

# subdir/CMakeLists.txt
message(${MY_VAR})  # 输出 "Hello"
```

**子目录 → 父目录：** 默认不可见（除非用 `PARENT_SCOPE`）

```cmake
# subdir/CMakeLists.txt
set(SUB_VAR "World" PARENT_SCOPE)

# 父 CMakeLists.txt
message(${SUB_VAR})  # 输出 "World"
```

### 目标的可见性

在子目录中创建的目标，在父目录和其他子目录中可见：

```cmake
# libs/book/CMakeLists.txt
add_library(booklib ...)

# app/CMakeLists.txt
target_link_libraries(app booklib)  # 可以直接使用
```

### 库的别名（ALIAS）

```cmake
add_library(Book::lib ALIAS booklib)
```

**好处：**
- 更清晰的命名空间
- 与 find_package 找到的库命名风格一致
- 防止名称冲突

使用别名：
```cmake
target_link_libraries(app Book::lib Utils::lib)
```

## 📝 练习题

### 练习 1：添加新模块

创建 `libs/user/` 模块，包含 `User` 类：
```cpp
class User {
    int id;
    std::string name;
    // ...
};
```

记得：
1. 创建 libs/user/CMakeLists.txt
2. 在顶层 CMakeLists.txt 添加 `add_subdirectory(libs/user)`
3. 在 app 中使用

### 练习 2：创建测试程序

在项目根目录创建 `tests/` 目录：
```
tests/
├── CMakeLists.txt
└── test_book.cpp
```

编写简单的测试程序，链接 booklib。

### 练习 3：条件编译子目录

使用选项控制是否编译测试：
```cmake
option(BUILD_TESTS "Build tests" OFF)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
```

然后用 `cmake -DBUILD_TESTS=ON ..` 开启测试。

### 练习 4：三层嵌套

在 libs/book/ 下再创建一个子目录 libs/book/formats/，
实现不同格式的图书（如电子书、纸质书）。

## ✅ 检查点

完成本课后，你应该能够回答：

- [ ] `add_subdirectory()` 的作用是什么？
- [ ] 子目录的 CMakeLists.txt 能访问父目录的变量吗？
- [ ] 在子目录中创建的库，能在另一个子目录中使用吗？
- [ ] 什么时候使用库的别名（ALIAS）？
- [ ] 如何组织一个包含多个模块的大型项目？

## 🎯 小结

本课核心要点：

1. **模块化**：每个模块有自己的 CMakeLists.txt
2. **add_subdirectory**：将子目录纳入构建系统
3. **变量作用域**：父→子可见，子→父需要 PARENT_SCOPE
4. **目标可见性**：子目录的目标在整个项目可见
5. **库别名**：`add_library(Name::lib ALIAS target)`

## 下一步

准备好了吗？前往 **第6课：编译选项和配置** 学习如何控制编译行为！

---

**项目组织最佳实践：**
- ✅ 每个库一个子目录
- ✅ 顶层 CMakeLists.txt 保持简洁
- ✅ 使用清晰的目录命名
- ✅ 库之间的依赖关系要清晰
- ✅ 可以独立编译和测试每个模块
