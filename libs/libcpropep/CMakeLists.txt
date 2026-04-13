add_library(cpropep_lib STATIC equilibrium.c print.c performance.c derivative.c)
target_include_directories(cpropep_lib PUBLIC include)
target_link_libraries(cpropep_lib PUBLIC compat num)
set_target_properties(cpropep_lib PROPERTIES OUTPUT_NAME cpropep)
