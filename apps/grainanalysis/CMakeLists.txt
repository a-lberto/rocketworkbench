# Build the drawstar app
add_executable(drawstar src/drawstar.c)
target_link_libraries(drawstar PRIVATE m)
