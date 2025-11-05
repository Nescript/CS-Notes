cmake_minimum_required(VERSION 3.10)
project(Calculator CXX)

# 使用变量管理源文件（推荐方法）
set(SOURCES
    main.cpp
    calculator.cpp
)

add_executable(calculator ${SOURCES})
