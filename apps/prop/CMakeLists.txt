add_executable(prop prop.c)
target_link_libraries(prop PRIVATE thermo cpropep_lib compat m)
