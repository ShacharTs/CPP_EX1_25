cmake_minimum_required(VERSION 3.10)
project(CPP_EX1_25)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)

# Ensure the project is compiled as a console application
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Add the source files
add_executable(CPP_EX1_25 Test.cpp Graph.cpp Node.cpp
        main.cpp)
