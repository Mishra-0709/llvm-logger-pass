cmake_minimum_required(VERSION 3.4.3)
project(LoggingPass)

find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

add_library(LoggingPass MODULE LoggingPass.cpp)
set_target_properties(LoggingPass PROPERTIES COMPILE_FLAGS "-fno-rtti")
