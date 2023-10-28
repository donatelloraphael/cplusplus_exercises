cmake_minimum_required(VERSION 3.26)
project(employee_management)

set(CMAKE_CXX_STANDARD 23)

add_executable(employee_management main.cpp
        Employee.h
        Employee.cpp
        EmployeeTest.cpp
        Database.h
        Database.cpp
        Database.cpp
        DatabaseTest.cpp)
