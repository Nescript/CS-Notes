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
    add_compile_options(-Wall -Wextra)
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

# 添加配置文件目录到全局 include
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# ==================== 提示信息 ====================
message(STATUS "")
message(STATUS "这是第7课的综合实战项目框架")
message(STATUS "请根据 README.md 的指导完成以下任务:")
message(STATUS "  1. 实现 libs/ 下的各个模块")
message(STATUS "  2. 完成 app/main.cpp")
message(STATUS "  3. 测试 Debug 和 Release 模式")
message(STATUS "  4. 在 Windows 和 Linux 下测试")
message(STATUS "")
message(STATUS "提示: 先完成一个简单的 main.cpp 测试构建系统")
message(STATUS "")
