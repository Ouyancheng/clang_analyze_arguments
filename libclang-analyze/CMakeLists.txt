cmake_minimum_required(VERSION 2.8)

set(libclang_include_path "/usr/local/Cellar/llvm/5.0.1/include")
set(libclang_lib_path "/usr/local/Cellar/llvm/5.0.1/lib")

project(libclang_analyze_arguments)
set(CMAKE_CXX_STANDARD 11)
include_directories(${libclang_include_path})
link_directories(${libclang_lib_path})
add_executable(clang_analyze_arguments main.cpp)
target_link_libraries(clang_analyze_arguments clang)
