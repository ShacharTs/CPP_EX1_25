cmake_minimum_required(VERSION 3.10)
project(CPP_EX1_25)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Ensure the project is compiled as a console application
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_executable(CPP_EX1_25
        PQueue.cpp
        UnionFind.cpp
        Graph.cpp
        Algorithms.cpp
        main.cpp
        Test.cpp
)

