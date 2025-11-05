#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>

namespace StringUtils {
    std::string toUpper(const std::string& str);
    std::string toLower(const std::string& str);
    std::string trim(const std::string& str);
}

#endif
