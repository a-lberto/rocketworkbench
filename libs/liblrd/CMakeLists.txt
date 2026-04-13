add_library(lrd_lib STATIC lrd.c)
target_include_directories(lrd_lib PUBLIC include)
set_target_properties(lrd_lib PROPERTIES OUTPUT_NAME lrd)
