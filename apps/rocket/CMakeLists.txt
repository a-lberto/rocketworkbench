# Build the rocket app
add_executable(rocket src/rocket.c)
target_link_libraries(rocket PRIVATE libcpropep libgpcp libcompat m)
