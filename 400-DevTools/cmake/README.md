# CMake 交互式学习课程

## 📚 课程简介

这是一套为 C/C++ 程序员设计的 CMake 实战课程。通过 7 个循序渐进的实践项目，你将从零开始掌握 CMake 构建系统。

## 🎯 学习目标

- 理解 CMake 的工作原理和构建流程
- 掌握 CMakeLists.txt 的编写
- 学会管理多文件、多模块项目
- 熟练使用静态库和动态库
- 掌握跨平台项目配置技巧

## 📖 课程大纲

### 第1课：最简单的 CMake 项目 ⭐
- **目标**：编译单个源文件
- **核心概念**：cmake_minimum_required, project, add_executable
- **时长**：15分钟
- **目录**：`lesson1-hello-cmake/`

### 第2课：多文件项目 ⭐
- **目标**：编译多个源文件到一个可执行文件
- **核心概念**：多文件管理，文件列表
- **时长**：20分钟
- **目录**：`lesson2-multiple-files/`

### 第3课：静态库和动态库 ⭐⭐
- **目标**：创建和链接库文件
- **核心概念**：add_library, target_link_libraries, STATIC/SHARED
- **时长**：30分钟
- **目录**：`lesson3-libraries/`

### 第4课：项目结构组织 ⭐⭐
- **目标**：规范的项目目录结构
- **核心概念**：include 目录，target_include_directories
- **时长**：25分钟
- **目录**：`lesson4-project-structure/`

### 第5课：子目录和模块化 ⭐⭐⭐
- **目标**：大型项目的模块化管理
- **核心概念**：add_subdirectory, 父子 CMakeLists.txt
- **时长**：35分钟
- **目录**：`lesson5-subdirectories/`

### 第6课：编译选项和配置 ⭐⭐⭐
- **目标**：控制编译行为
- **核心概念**：CMAKE_BUILD_TYPE, 编译器标志，条件编译
- **时长**：30分钟
- **目录**：`lesson6-build-options/`

### 第7课：综合实战项目 ⭐⭐⭐
- **目标**：构建一个完整的 C++ 项目
- **综合应用**：所有前面学到的知识
- **时长**：45分钟
- **目录**：`lesson7-final-project/`

## 🚀 如何使用本课程

### 环境要求

- **Windows**：已安装 CMake（推荐 3.10+）
- **WSL Ubuntu**：可选，用于学习跨平台构建

### 学习方式

1. **按顺序学习**：从第1课开始，逐课推进
2. **动手实践**：每一课都要亲自运行命令
3. **修改代码**：尝试修改 CMakeLists.txt，观察效果
4. **完成练习**：每课最后都有练习题

### 基本工作流程

```bash
# 在 Windows PowerShell 中
cd lesson1-hello-cmake
mkdir build
cd build
cmake ..
cmake --build .
./Debug/hello.exe  # 或 Release/hello.exe

# 在 WSL Ubuntu 中
cd lesson1-hello-cmake
mkdir build && cd build
cmake ..
make
./hello
```

## 📝 学习建议

1. **先看文档**：每个课程目录下都有详细的 `README.md`
2. **理解再写**：不要直接复制，理解每一行的含义
3. **实验精神**：多尝试修改，看看会发生什么
4. **记录笔记**：把遇到的问题和解决方案记下来
5. **对比平台**：在 Windows 和 Linux 下都试试

## 🛠️ 常用 CMake 命令速查

```bash
# 生成构建文件
cmake -S . -B build          # 指定源目录和构建目录
cmake -B build               # 当前目录为源目录

# 编译项目
cmake --build build          # 跨平台编译命令
cmake --build build --config Release  # 指定配置

# 清理
rm -rf build                 # 删除构建目录（最彻底）

# 查看变量
cmake -L                     # 列出缓存变量
cmake --system-information   # 系统信息
```

## 🎓 学完之后

完成这 7 课后，你将能够：
- ✅ 为自己的 C++ 项目编写 CMakeLists.txt
- ✅ 理解并维护开源项目的 CMake 构建脚本
- ✅ 组织大型多模块 C++ 项目
- ✅ 处理跨平台编译问题

## 📚 进阶学习资源

- [CMake 官方文档](https://cmake.org/documentation/)
- [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)
- [Modern CMake](https://cliutils.gitlab.io/modern-cmake/)

## 💬 学习记录

| 课程 | 完成日期 | 掌握程度 | 备注 |
|------|---------|---------|------|
| 第1课 |         |         |      |
| 第2课 |         |         |      |
| 第3课 |         |         |      |
| 第4课 |         |         |      |
| 第5课 |         |         |      |
| 第6课 |         |         |      |
| 第7课 |         |         |      |

---

**准备好了吗？让我们从第1课开始！** 🚀
