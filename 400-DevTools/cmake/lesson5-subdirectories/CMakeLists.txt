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
