cmake_minimum_required(VERSION 3.15)
project(csapp_code_sample C)

set(CMAKE_C_STANDARD 99)

include_directories(code3e/include)

# 运行客户端
#add_executable(csapp_code_sample code3e/netp/echoclient.c code3e/src/csapp.c)
# 运行服务器
#add_executable(csapp_code_sample code3e/netp/echoserveri.c code3e/netp/echo.c code3e/src/csapp.c)

# 运行 tiny web 服务器 (见code3e.md文档11.6节)
add_executable(csapp_code_sample code3e/netp/tiny/tiny.c code3e/src/csapp.c)

# linux下需要添加 pthread 库
target_link_libraries(csapp_code_sample pthread)