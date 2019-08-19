cmake_minimum_required(VERSION 3.0.0)
project(sparse VERSION 1.0.0)

add_executable(sparse src/main.cpp src/config.cpp src/file.cpp src/memory.cpp src/stats.cpp)

target_include_directories(sparse PRIVATE src/include)

include(CTest)
enable_testing()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
