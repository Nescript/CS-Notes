cmake_minimum_required(VERSION 3.10)
project(StudentSystem CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 收集库的源文件
set(LIB_SOURCES
    src/Student.cpp
    src/StudentManager.cpp
)

# 创建库
add_library(studentlib STATIC ${LIB_SOURCES})

# 为库指定 include 目录（PUBLIC 表示使用这个库的目标也能看到这个目录）
target_include_directories(studentlib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 创建可执行文件
add_executable(student_app src/main.cpp)

# 链接库（会自动继承库的 include 目录）
target_link_libraries(student_app studentlib)
