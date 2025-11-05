cmake_minimum_required(VERSION 3.10)
project(MathLibProject CXX)

# 创建静态库（可以改为 SHARED 创建动态库）
add_library(mathlib STATIC mathlib.cpp)

# 创建可执行文件
add_executable(app main.cpp)

# 链接库到可执行文件
target_link_libraries(app mathlib)
