add_library(thermo STATIC load.c thermo.c)
target_include_directories(thermo PUBLIC include)
target_link_libraries(thermo PUBLIC cpropep_lib)
