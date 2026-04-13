add_library(rockflight_lib STATIC eom.c atmos.c aero.c engine.c mass.c stage.c rocket.c evaluate_function.c)
target_include_directories(rockflight_lib PUBLIC include)
set_target_properties(rockflight_lib PROPERTIES OUTPUT_NAME rockflight)
