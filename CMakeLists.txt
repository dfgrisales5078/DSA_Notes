cmake_minimum_required(VERSION 3.21)
project(DSA_Notes)

set(CMAKE_CXX_STANDARD 14)

add_executable(DSA_Notes main.cpp stack.h DynamicList.cpp DynamicList.h DynamicQueue.cpp DynamicQueue.h BinSearchTree.cpp BinSearchTree.h)
