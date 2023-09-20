cmake_minimum_required(VERSION 3.5)

project(TheLife)

add_executable(TheLife 
    "TheLife.cpp"
    "main.cpp"   
    "TheLife.h")

set_target_properties(TheLife PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
