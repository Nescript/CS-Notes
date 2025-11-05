# 第6课：编译选项和配置

## 🎯 学习目标

- 掌握 Debug 和 Release 构建类型
- 学会设置编译器标志（flags）
- 理解条件编译和选项（option）
- 学会使用 CMake 变量控制编译行为

## 📖 知识点

### 构建类型（Build Types）

CMake 支持多种构建类型：

| 构建类型 | 说明 | 优化级别 | 调试信息 |
|---------|------|---------|---------|
| **Debug** | 调试版本 | 无优化 (-O0) | 完整 (-g) |
| **Release** | 发布版本 | 高优化 (-O3) | 无 |
| **RelWithDebInfo** | 带调试信息的发布版 | 优化 (-O2) | 有 (-g) |
| **MinSizeRel** | 最小体积发布版 | 大小优化 (-Os) | 无 |

### 编译器标志（Compiler Flags）

- **警告标志**: `-Wall`, `-Wextra`, `-Werror`
- **优化标志**: `-O0`, `-O1`, `-O2`, `-O3`, `-Os`
- **调试标志**: `-g`, `-ggdb`
- **C++ 标准**: `-std=c++11`, `-std=c++14`, `-std=c++17`

## 💻 实践项目：配置化编译

### 项目结构

```
lesson6-build-options/
├── CMakeLists.txt
├── main.cpp
├── config.h.in          # 配置模板文件
└── README.md
```

### 源代码

#### main.cpp
```cpp
#include <iostream>
#include "config.h"  // CMake 生成的配置文件

int main() {
    std::cout << "=== 项目信息 ===" << std::endl;
    std::cout << "项目名称: " << PROJECT_NAME << std::endl;
    std::cout << "版本号: " << VERSION_MAJOR << "." 
              << VERSION_MINOR << "." << VERSION_PATCH << std::endl;
    
#ifdef ENABLE_DEBUG_OUTPUT
    std::cout << "[DEBUG] 调试输出已启用" << std::endl;
#endif

#ifdef USE_ADVANCED_FEATURES
    std::cout << "[INFO] 使用高级功能" << std::endl;
#else
    std::cout << "[INFO] 使用基础功能" << std::endl;
#endif
    
    std::cout << "\n构建类型: " << CMAKE_BUILD_TYPE << std::endl;
    
    return 0;
}
```

#### config.h.in（配置模板）
```cpp
#ifndef CONFIG_H
#define CONFIG_H

#define PROJECT_NAME "@PROJECT_NAME@"
#define VERSION_MAJOR @PROJECT_VERSION_MAJOR@
#define VERSION_MINOR @PROJECT_VERSION_MINOR@
#define VERSION_PATCH @PROJECT_VERSION_PATCH@

#cmakedefine ENABLE_DEBUG_OUTPUT
#cmakedefine USE_ADVANCED_FEATURES

#define CMAKE_BUILD_TYPE "@CMAKE_BUILD_TYPE@"

#endif // CONFIG_H
```

### CMakeLists.txt（完整版）

```cmake
cmake_minimum_required(VERSION 3.10)

# 项目名称和版本
project(ConfigurableApp VERSION 1.2.3 LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # 禁用编译器扩展

# ==================== 选项 ====================
option(ENABLE_DEBUG_OUTPUT "Enable debug output" OFF)
option(USE_ADVANCED_FEATURES "Use advanced features" ON)
option(BUILD_TESTS "Build test programs" OFF)

# ==================== 构建类型 ====================
# 如果未指定，默认为 Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# ==================== 编译器标志 ====================
# 通用编译标志
add_compile_options(
    -Wall           # 所有警告
    -Wextra         # 额外警告
)

# Debug 特定的标志
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-g)      # 调试信息
    add_definitions(-DDEBUG)     # 定义 DEBUG 宏
endif()

# Release 特定的标志
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_options(-O3)     # 最高优化
    add_definitions(-DNDEBUG)    # 禁用 assert
endif()

# Windows 特定设置
if(MSVC)
    add_compile_options(/W4)     # 警告级别 4
    add_compile_options(/utf-8)  # UTF-8 编码
endif()

# ==================== 配置文件生成 ====================
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/config.h
    @ONLY
)

# ==================== 可执行文件 ====================
add_executable(app main.cpp)

# 添加生成的 config.h 的路径
target_include_directories(app PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

# ==================== 平台特定链接 ====================
if(WIN32)
    # Windows 特定库
    # target_link_libraries(app ws2_32)
elseif(UNIX)
    # Linux 特定库
    # target_link_libraries(app pthread)
endif()

# ==================== 输出信息 ====================
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "Debug output: ${ENABLE_DEBUG_OUTPUT}")
message(STATUS "Advanced features: ${USE_ADVANCED_FEATURES}")
message(STATUS "Build tests: ${BUILD_TESTS}")
```

## 🚀 动手操作

### 1. Debug 模式编译

```powershell
# Windows
cd "d:\Obsidian Library\信息学奥赛笔记\300 语言\cmake\lesson6-build-options"
mkdir build-debug
cd build-debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
.\Debug\app.exe
```

### 2. Release 模式编译

```powershell
cd ..
mkdir build-release
cd build-release
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
.\Release\app.exe
```

### 3. 启用选项

```powershell
cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_DEBUG_OUTPUT=ON -DUSE_ADVANCED_FEATURES=OFF ..
cmake --build .
```

### 4. Linux 下操作

```bash
# Debug
mkdir build-debug && cd build-debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
make VERBOSE=1  # 显示详细编译命令
./app

# Release
cd .. && mkdir build-release && cd build-release
cmake -DCMAKE_BUILD_TYPE=Release ..
make
./app
```

## 🔍 深入理解

### 1. option 命令

```cmake
option(变量名 "说明" 默认值)
```

**使用方式：**
```cmake
option(ENABLE_LOGGING "Enable logging" ON)

if(ENABLE_LOGGING)
    add_definitions(-DENABLE_LOGGING)
endif()
```

**命令行设置：**
```bash
cmake -DENABLE_LOGGING=OFF ..
```

### 2. configure_file

```cmake
configure_file(输入文件 输出文件 [选项])
```

**作用：** 将模板文件中的变量替换为实际值

**模板语法：**
- `@变量名@`: 替换为变量的值
- `#cmakedefine 变量`: 如果变量为真，生成 `#define 变量`

**示例：**
```cpp
// config.h.in
#define VERSION "@PROJECT_VERSION@"
#cmakedefine ENABLE_FEATURE

// 生成的 config.h (如果 ENABLE_FEATURE=ON)
#define VERSION "1.2.3"
#define ENABLE_FEATURE
```

### 3. 编译器标志设置方式

#### 方法一：add_compile_options（全局）
```cmake
add_compile_options(-Wall -Wextra)
```
影响所有目标。

#### 方法二：target_compile_options（目标特定）
```cmake
target_compile_options(myapp PRIVATE -Wall)
```
只影响指定目标，推荐使用。

#### 方法三：set(CMAKE_CXX_FLAGS)（不推荐）
```cmake
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
```
会覆盖 CMake 的默认设置，不推荐。

### 4. 条件编译

```cmake
# 根据构建类型
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Debug 特定设置
endif()

# 根据平台
if(WIN32)
    # Windows
elseif(UNIX)
    # Linux/Mac
endif()

# 根据编译器
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # GCC
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # Visual C++
endif()
```

## 📝 练习题

### 练习 1：对比 Debug 和 Release

编译两个版本，对比：
1. 可执行文件大小
2. 运行速度（用循环测试）
3. 是否包含调试符号（Linux: `file app`）

### 练习 2：添加自定义选项

添加选项控制是否启用颜色输出：
```cmake
option(ENABLE_COLOR_OUTPUT "Enable color output" ON)
```

在代码中根据这个宏输出不同颜色。

### 练习 3：多配置生成器

Windows 下使用 Visual Studio 生成器：
```powershell
cmake -G "Visual Studio 16 2019" ..
cmake --build . --config Debug
cmake --build . --config Release
```

观察生成的目录结构。

### 练习 4：编译器警告测试

故意写一些有警告的代码（如未使用的变量），然后：
```cmake
target_compile_options(app PRIVATE -Werror)  # 把警告当错误
```

看看会发生什么。

## ✅ 检查点

完成本课后，你应该能够回答：

- [ ] Debug 和 Release 的主要区别是什么？
- [ ] `option()` 命令的作用是什么？
- [ ] `configure_file()` 用于做什么？
- [ ] 如何在命令行指定构建类型？
- [ ] `target_compile_options` 和 `add_compile_options` 的区别？

## 🎯 小结

本课核心要点：

1. **构建类型**: Debug (调试) vs Release (发布)
2. **选项**: `option()` 定义可配置项
3. **条件编译**: 根据选项和平台进行不同的编译
4. **配置文件**: `configure_file()` 生成头文件
5. **编译标志**: 控制警告、优化等行为

## 下一步

恭喜！前往 **第7课：综合实战项目** 应用所有学到的知识！

---

**常用命令速查：**
```bash
# 指定构建类型
cmake -DCMAKE_BUILD_TYPE=Release ..

# 设置选项
cmake -DOPTION_NAME=ON ..

# 查看所有选项
cmake -L ..

# 详细编译输出
make VERBOSE=1          # Linux
cmake --build . --verbose  # 跨平台
```
