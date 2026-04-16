# Build the main cpropep app
add_executable(cpropep src/cpropep.c)
target_link_libraries(cpropep PRIVATE libcpropep libnum libcompat m)
