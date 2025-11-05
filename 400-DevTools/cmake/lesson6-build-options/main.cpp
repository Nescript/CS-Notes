#include <iostream>
#include "config.h"  // CMake 生成的配置文件

int main() {
    std::cout << "=== 项目信息 ===" << std::endl;
    std::cout << "项目名称: " << PROJECT_NAME << std::endl;
    std::cout << "版本号: " << VERSION_MAJOR << "." 
              << VERSION_MINOR << "." << VERSION_PATCH << std::endl;
    
#ifdef ENABLE_DEBUG_OUTPUT
    std::cout << "[DEBUG] 调试输出已启用" << std::endl;
#endif

#ifdef USE_ADVANCED_FEATURES
    std::cout << "[INFO] 使用高级功能" << std::endl;
#else
    std::cout << "[INFO] 使用基础功能" << std::endl;
#endif
    
    std::cout << "\n构建类型: " << CMAKE_BUILD_TYPE << std::endl;
    
    return 0;
}
