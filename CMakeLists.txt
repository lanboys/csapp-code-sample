cmake_minimum_required(VERSION 3.15)
project(csapp_code_sample C)

set(CMAKE_C_STANDARD 99)

include_directories(code3e/include)

add_executable(csapp_code_sample code3e/netp/echoclient.c code3e/src/csapp.c)

# linux下需要添加 pthread 库
target_link_libraries(csapp_code_sample PRIVATE pthread)