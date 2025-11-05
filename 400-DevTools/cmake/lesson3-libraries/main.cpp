#include <iostream>
#include "mathlib.h"

int main() {
    std::cout << "=== 使用 MathLib 静态/动态库 ===" << std::endl;
    
    std::cout << "5 的平方: " << MathLib::square(5) << std::endl;
    std::cout << "3 的立方: " << MathLib::cube(3) << std::endl;
    std::cout << "5 的阶乘: " << MathLib::factorial(5) << std::endl;
    std::cout << "17 是质数吗? " << (MathLib::isPrime(17) ? "是" : "否") << std::endl;
    
    return 0;
}
