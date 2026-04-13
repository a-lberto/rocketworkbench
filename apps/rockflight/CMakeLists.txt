add_executable(rockflight parser.c print.c simulate.c check.c rockflight.c)
target_link_libraries(rockflight PRIVATE rockflight_lib num m)
