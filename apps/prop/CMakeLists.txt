# Build the main prop app
add_executable(prop src/prop.c)
target_link_libraries(prop PRIVATE libcpropep libcompat m)

# Build the plot app
add_executable(prop-plot src/plot.c)
target_link_libraries(prop-plot PRIVATE libcpropep libcompat m)
