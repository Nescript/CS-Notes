#include <iostream>
#include "book/Book.h"
#include "utils/StringUtils.h"

int main() {
    std::cout << "=== 图书管理系统 ===" << std::endl;
    std::cout << std::endl;
    
    // 创建图书
    Book book1(1, "C++ Primer", "Stanley B. Lippman", 128.00);
    Book book2(2, "Effective C++", "Scott Meyers", 79.00);
    Book book3(3, "The C++ Programming Language", "Bjarne Stroustrup", 139.00);
    
    // 打印图书列表
    std::cout << "图书列表：" << std::endl;
    book1.print();
    book2.print();
    book3.print();
    std::cout << std::endl;
    
    // 使用工具函数
    std::string title = "c++ primer";
    std::cout << "原标题: " << title << std::endl;
    std::cout << "大写: " << StringUtils::toUpper(title) << std::endl;
    std::cout << "小写: " << StringUtils::toLower("EFFECTIVE C++") << std::endl;
    
    return 0;
}
