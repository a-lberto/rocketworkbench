# Build the main cpropep app
add_executable(cpropep src/cpropep.c)
target_link_libraries(cpropep PRIVATE libcpropep libnum libcompat m)

# Build cpropep-web
add_executable(cpropep-web src/cpropep-web.c)
target_link_libraries(cpropep-web PRIVATE libcpropep cgilib m)
if(WIN32)
    target_link_libraries(cpropep-web PRIVATE syslog-win ws2_32)
endif()
