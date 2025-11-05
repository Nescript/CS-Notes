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
# 通用编译标志（仅对 GCC/Clang）
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
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
