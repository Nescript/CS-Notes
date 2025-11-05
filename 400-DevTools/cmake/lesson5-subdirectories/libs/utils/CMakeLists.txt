# 工具模块的 CMakeLists.txt

set(UTILS_SOURCES
    src/StringUtils.cpp
)

add_library(utilslib STATIC ${UTILS_SOURCES})

target_include_directories(utilslib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(Utils::lib ALIAS utilslib)
