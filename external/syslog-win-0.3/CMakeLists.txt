cmake_minimum_required(VERSION 3.10)
project(syslog-win C)

include_directories(include)

add_library(syslog-win STATIC
    client/syslog-client.c
)
