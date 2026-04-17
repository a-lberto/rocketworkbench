cmake_minimum_required(VERSION 3.10)
project(cgilib C)

add_library(cgilib STATIC 
    cgi.c 
    cgiaux.c 
    cookies.c
)

target_include_directories(cgilib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../syslog-win-0.3/include
)
