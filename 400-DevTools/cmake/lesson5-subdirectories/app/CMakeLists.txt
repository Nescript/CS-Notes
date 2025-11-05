# 应用程序的 CMakeLists.txt

add_executable(bookapp main.cpp)

# 链接两个库
target_link_libraries(bookapp
    booklib
    utilslib
)
