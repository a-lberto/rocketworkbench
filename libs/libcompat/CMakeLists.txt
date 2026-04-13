add_library(compat STATIC compat.c getopt.c)
target_include_directories(compat PUBLIC include)
