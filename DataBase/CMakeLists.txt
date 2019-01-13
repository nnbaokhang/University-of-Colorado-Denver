cmake_minimum_required(VERSION 3.12)
project(DataBase)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataBase main.cpp BSTree.hpp MenuDriver.cpp readFromFile.cpp function.cpp)