cmake_minimum_required(VERSION 3.28)
project(DataStructures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (${RED_BLACK_TREE_ENABLE})
    add_subdirectory(RedBlackTree)
endif()