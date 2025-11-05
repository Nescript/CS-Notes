# 指定 CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 定义项目名称和使用的语言
project(HelloCMake CXX)

# 添加可执行文件目标
add_executable(hello main.cpp)
