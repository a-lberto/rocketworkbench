add_executable(lrd main.c lrd_load.c)
target_link_libraries(lrd PRIVATE lrd_lib thermo cpropep_lib num m)
