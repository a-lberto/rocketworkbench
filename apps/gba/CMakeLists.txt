add_executable(grain gba.c grain.c shape.c output.c)
target_link_libraries(grain PRIVATE m)
