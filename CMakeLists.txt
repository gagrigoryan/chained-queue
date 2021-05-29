cmake_minimum_required(VERSION 3.17)
project(queue)

set(CMAKE_CXX_STANDARD 14)

add_executable(queue main.cpp TwoThreeNode.h TwoThreeNode.cpp TwoThreeTree.h TwoThreeTree.cpp Queue.h Queue.cpp)