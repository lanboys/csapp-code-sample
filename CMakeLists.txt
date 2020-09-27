cmake_minimum_required(VERSION 3.15)
project(csapp_code_sample C)

set(CMAKE_C_STANDARD 99)

include_directories(./code3e/include)

add_executable(csapp_code_sample main.c ./code3e/src/csapp.c)