# 第7课：综合实战项目

## 🎯 学习目标

- 综合应用前6课所学知识
- 构建一个完整的 C++ 项目
- 掌握实际项目的 CMake 最佳实践
- 学会项目的打包和发布

## 💻 实战项目：简易数据处理系统

一个包含多个模块的数据处理系统，演示真实项目的组织方式。

### 项目特点

✅ 多模块架构  
✅ 静态库和动态库  
✅ 规范的目录结构  
✅ 可配置的编译选项  
✅ Debug/Release 构建  
✅ 跨平台支持  

### 项目结构

```
lesson7-final-project/
├── CMakeLists.txt              # 顶层 CMake
├── README.md
├── config.h.in                 # 配置模板
├── libs/                       # 库模块
│   ├── datacore/              # 数据核心库
│   │   ├── CMakeLists.txt
│   │   ├── include/
│   │   │   └── datacore/
│   │   │       ├── DataPoint.h
│   │   │       └── DataSet.h
│   │   └── src/
│   │       ├── DataPoint.cpp
│   │       └── DataSet.cpp
│   ├── analyzer/              # 分析器库
│   │   ├── CMakeLists.txt
│   │   ├── include/
│   │   │   └── analyzer/
│   │   │       └── StatAnalyzer.h
│   │   └── src/
│   │       └── StatAnalyzer.cpp
│   └── utils/                 # 工具库
│       ├── CMakeLists.txt
│       ├── include/
│       │   └── utils/
│       │       ├── Logger.h
│       │       └── Timer.h
│       └── src/
│           ├── Logger.cpp
│           └── Timer.cpp
└── app/                       # 应用程序
    ├── CMakeLists.txt
    └── main.cpp
```

## 📝 实现说明

由于篇幅限制，这里提供核心文件的框架。你需要根据前面的课程知识完成剩余部分。

### 顶层 CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.10)
project(DataProcessingSystem VERSION 2.0.0 LANGUAGES CXX)

# ==================== 全局设置 ====================
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 输出目录设置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# ==================== 选项 ====================
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(ENABLE_LOGGING "Enable logging" ON)
option(ENABLE_PROFILING "Enable profiling" OFF)
option(BUILD_EXAMPLES "Build example programs" ON)

# ==================== 构建类型 ====================
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

message(STATUS "========================================")
message(STATUS "  项目: ${PROJECT_NAME}")
message(STATUS "  版本: ${PROJECT_VERSION}")
message(STATUS "  构建类型: ${CMAKE_BUILD_TYPE}")
message(STATUS "  共享库: ${BUILD_SHARED_LIBS}")
message(STATUS "  日志: ${ENABLE_LOGGING}")
message(STATUS "  性能分析: ${ENABLE_PROFILING}")
message(STATUS "========================================")

# ==================== 编译选项 ====================
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(-g -O0)
    else()
        add_compile_options(-O3)
    endif()
endif()

if(MSVC)
    add_compile_options(/W4 /utf-8)
endif()

# ==================== 配置文件 ====================
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/config.h
    @ONLY
)

# ==================== 添加子目录 ====================
add_subdirectory(libs/datacore)
add_subdirectory(libs/analyzer)
add_subdirectory(libs/utils)
add_subdirectory(app)

# ==================== 安装规则（可选） ====================
install(TARGETS datacore analyzer utils
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin)

# ==================== 打包（可选） ====================
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_VENDOR "Your Name")
include(CPack)
```

### config.h.in

```cpp
#ifndef CONFIG_H
#define CONFIG_H

// 项目信息
#define PROJECT_NAME "@PROJECT_NAME@"
#define PROJECT_VERSION "@PROJECT_VERSION@"
#define PROJECT_VERSION_MAJOR @PROJECT_VERSION_MAJOR@
#define PROJECT_VERSION_MINOR @PROJECT_VERSION_MINOR@
#define PROJECT_VERSION_PATCH @PROJECT_VERSION_PATCH@

// 构建配置
#define BUILD_TYPE "@CMAKE_BUILD_TYPE@"

// 功能开关
#cmakedefine ENABLE_LOGGING
#cmakedefine ENABLE_PROFILING

// 平台检测
#ifdef _WIN32
    #define PLATFORM "Windows"
#elif __linux__
    #define PLATFORM "Linux"
#elif __APPLE__
    #define PLATFORM "macOS"
#else
    #define PLATFORM "Unknown"
#endif

#endif // CONFIG_H
```

## 🚀 构建和运行

### 基础构建

```powershell
# Windows
cd "d:\Obsidian Library\信息学奥赛笔记\300 语言\cmake\lesson7-final-project"
mkdir build
cd build
cmake ..
cmake --build .
.\bin\Debug\dataapp.exe
```

### 高级构建选项

```bash
# Debug 模式，启用所有功能
cmake -DCMAKE_BUILD_TYPE=Debug \
      -DENABLE_LOGGING=ON \
      -DENABLE_PROFILING=ON \
      -DBUILD_SHARED_LIBS=OFF \
      ..

# Release 模式，编译共享库
cmake -DCMAKE_BUILD_TYPE=Release \
      -DBUILD_SHARED_LIBS=ON \
      ..

# 并行编译
cmake --build . -j8

# 运行
./bin/dataapp
```

## 📝 练习任务

### 任务 1：完成基础实现
实现以下类：
1. `DataPoint`: 数据点类（x, y 坐标）
2. `DataSet`: 数据集类（管理多个 DataPoint）
3. `StatAnalyzer`: 统计分析器（计算平均值、方差等）
4. `Logger`: 日志工具
5. `Timer`: 性能计时器

### 任务 2：模块化编译
确保每个库都能：
- 独立编译
- 正确链接依赖
- 导出头文件路径

### 任务 3：配置管理
1. 根据 `ENABLE_LOGGING` 控制日志输出
2. 根据 `ENABLE_PROFILING` 启用性能统计
3. 支持 Debug 和 Release 模式

### 任务 4：跨平台测试
在 Windows 和 Linux (WSL) 下分别编译运行，确保：
- 编译成功
- 运行正常
- 路径处理正确

### 任务 5：性能优化
1. 对比 Debug 和 Release 的性能差异
2. 测试静态库和动态库的启动时间
3. 使用 Timer 测量关键函数耗时

## ✅ 完成标准

完成本项目后，你应该能够：

- [ ] 组织多模块 C++ 项目
- [ ] 编写清晰的 CMakeLists.txt
- [ ] 管理库之间的依赖关系
- [ ] 使用编译选项和条件编译
- [ ] 在不同平台上构建项目
- [ ] 理解 Debug 和 Release 的区别
- [ ] 生成配置头文件
- [ ] 设置输出目录

## 🎯 项目扩展建议

继续深入学习：

1. **测试框架**：集成 Google Test 或 Catch2
2. **文档生成**：使用 Doxygen
3. **代码格式化**：集成 clang-format
4. **CI/CD**：设置 GitHub Actions
5. **外部依赖**：使用 find_package 引入第三方库
6. **安装和打包**：学习 install() 和 CPack

## 🎓 总结

恭喜你完成了 CMake 学习课程！你现在已经掌握：

### 核心技能
✅ CMakeLists.txt 的编写  
✅ 多文件项目管理  
✅ 静态库和动态库的创建  
✅ 规范的项目结构组织  
✅ 子目录和模块化  
✅ 编译选项和配置  
✅ 跨平台构建  

### 下一步
- 研究开源项目的 CMake 配置
- 学习 Modern CMake 最佳实践
- 探索 CMake 的高级功能（测试、打包、安装等）
- 为自己的项目编写 CMake 构建脚本

## 📚 参考资源

- [CMake 官方文档](https://cmake.org/cmake/help/latest/)
- [Modern CMake](https://cliutils.gitlab.io/modern-cmake/)
- [Effective Modern CMake](https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1)
- [CMake Cookbook](https://github.com/dev-cafe/cmake-cookbook)

---

**继续学习！CMake 的世界还有很多值得探索的内容！** 🚀

记得在 README.md 的学习记录表中标记你的进度！
