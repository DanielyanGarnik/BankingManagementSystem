cmake_minimum_required(VERSION 3.16)

project(BankingManagementSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(BankingManagementSystem
    src/main.cpp
    src/Account.cpp
    src/Bank.cpp
)

target_include_directories(BankingManagementSystem PRIVATE include)
