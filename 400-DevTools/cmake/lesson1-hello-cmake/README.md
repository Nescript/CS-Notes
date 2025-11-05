# 第1课：最简单的 CMake 项目

## 🎯 学习目标

- 理解 CMake 的基本工作流程
- 学会编写最简单的 CMakeLists.txt
- 掌握 CMake 的生成和编译命令
- 理解 out-of-source build（外部构建）

## 📖 知识点

### CMake 是什么？

CMake 是一个**跨平台的构建系统生成器**。它不直接编译代码，而是生成本地构建工具需要的文件：
- Windows 上生成 Visual Studio 项目或 NMake 文件
- Linux 上生成 Makefile
- 其他平台生成相应的构建文件

### 基本工作流程

```
源代码 + CMakeLists.txt  →  [CMake生成]  →  构建文件  →  [编译器]  →  可执行文件
```

1. **配置阶段（Configure）**：CMake 读取 CMakeLists.txt，生成构建文件
2. **生成阶段（Generate）**：生成特定构建系统的文件
3. **编译阶段（Build）**：使用本地工具编译代码

## 💻 实践项目

### 项目结构

```
lesson1-hello-cmake/
├── CMakeLists.txt       # CMake 配置文件
├── main.cpp             # 源代码
└── README.md            # 本文件
```

### 源代码：main.cpp

这是一个简单的 Hello World 程序：

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, CMake!" << std::endl;
    std::cout << "这是我的第一个 CMake 项目！" << std::endl;
    return 0;
}
```

### CMakeLists.txt 详解

```cmake
# 指定 CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 定义项目名称和使用的语言
project(HelloCMake CXX)

# 添加可执行文件目标
add_executable(hello main.cpp)
```

**逐行解释：**

1. `cmake_minimum_required(VERSION 3.10)`
   - 指定需要的 CMake 最低版本
   - 如果用户的 CMake 版本太低，会报错
   - 3.10 是一个比较通用的版本

2. `project(HelloCMake CXX)`
   - 定义项目名称为 "HelloCMake"
   - `CXX` 表示这是一个 C++ 项目
   - 还可以是 `C`, `Java`, `Fortran` 等

3. `add_executable(hello main.cpp)`
   - 创建一个名为 "hello" 的可执行文件目标
   - 使用 main.cpp 作为源文件
   - 编译后会生成 hello.exe（Windows）或 hello（Linux）

## 🚀 动手操作

### 在 Windows PowerShell 中

```powershell
# 1. 进入项目目录
cd "d:\Obsidian Library\信息学奥赛笔记\300 语言\cmake\lesson1-hello-cmake"

# 2. 创建构建目录（重要：不要在源代码目录直接构建！）
mkdir build
cd build

# 3. 运行 CMake 生成构建文件
cmake ..

# 4. 编译项目
cmake --build .

# 5. 运行程序
.\Debug\hello.exe
# 或者，如果是 Release 模式
# .\Release\hello.exe
```

### 在 WSL Ubuntu 中

```bash
# 1. 进入项目目录
cd /mnt/d/Obsidian\ Library/信息学奥赛笔记/300\ 语言/cmake/lesson1-hello-cmake

# 2. 创建构建目录
mkdir build && cd build

# 3. 运行 CMake
cmake ..

# 4. 编译（Linux 下使用 make）
make

# 5. 运行程序
./hello
```

## 🔍 深入理解

### 为什么要创建 build 目录？

这叫做 **Out-of-Source Build**（外部构建）：

**好处：**
- ✅ 保持源代码目录整洁
- ✅ 可以同时维护多个构建配置（Debug, Release）
- ✅ 容易清理：直接删除 build 目录即可

**不好的做法：**
```bash
# ❌ 不要这样做
cmake .  # 在源代码目录直接生成，会产生很多中间文件
```

### cmake 命令详解

```bash
# 基本用法
cmake [选项] <源代码目录>

# 常用选项
cmake -S . -B build          # -S 指定源目录，-B 指定构建目录
cmake -G "Visual Studio 16"  # -G 指定生成器
cmake -DCMAKE_BUILD_TYPE=Release  # -D 设置变量
```

### 构建目录里有什么？

运行 `cmake ..` 后，build 目录会生成：
- `CMakeCache.txt` - CMake 缓存文件
- `CMakeFiles/` - CMake 内部文件
- `Makefile` (Linux) 或 `.sln` (Windows) - 构建系统文件

## 📝 练习题

### 练习 1：修改项目名称
将 `project(HelloCMake CXX)` 改为你自己的名字，重新构建，观察有什么变化。

### 练习 2：修改可执行文件名
将 `add_executable(hello main.cpp)` 的 `hello` 改为 `myapp`，看看生成的文件名有什么变化。

### 练习 3：添加输出信息
在 CMakeLists.txt 中添加一行：
```cmake
message("正在配置 HelloCMake 项目...")
```
重新运行 `cmake ..`，看看会输出什么。

### 练习 4：跨平台实验
如果你有 WSL，尝试在 Windows 和 Linux 下分别编译，对比生成文件的区别。

## ✅ 检查点

完成本课后，你应该能够回答：

- [ ] CMake 和编译器（如 g++、msvc）的区别是什么？
- [ ] 为什么要用 build 目录，而不是在源代码目录直接运行 cmake？
- [ ] `cmake ..` 和 `cmake --build .` 分别做了什么？
- [ ] CMakeLists.txt 中的三个核心命令是什么作用？

## 🎯 小结

恭喜！你已经完成了第一个 CMake 项目。核心要点：

1. **三个必备命令**：`cmake_minimum_required`, `project`, `add_executable`
2. **两步构建流程**：`cmake ..`（生成） + `cmake --build .`（编译）
3. **外部构建原则**：始终使用独立的 build 目录

## 下一步

准备好了吗？前往 **第2课：多文件项目** 学习如何管理多个源文件！

---

**遇到问题？** 常见错误：
- ❌ `CMake Error: The source directory does not appear to contain CMakeLists.txt`
  - 检查是否在正确的目录
- ❌ `No CMAKE_CXX_COMPILER could be found`
  - 需要安装 C++ 编译器（Windows: Visual Studio, Linux: g++）
