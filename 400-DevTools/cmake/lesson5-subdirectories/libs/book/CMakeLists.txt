# 图书模块的 CMakeLists.txt

# 收集源文件
set(BOOK_SOURCES
    src/Book.cpp
)

# 创建库
add_library(booklib STATIC ${BOOK_SOURCES})

# 指定 include 目录
target_include_directories(booklib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 可选：设置库的别名，便于使用
add_library(Book::lib ALIAS booklib)
