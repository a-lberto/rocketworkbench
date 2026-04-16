# Collect production source files from the src directory
file(GLOB SRCS "src/parser.c")

add_library(libprofiler STATIC ${SRCS})
set_target_properties(libprofiler PROPERTIES OUTPUT_NAME profiler)

target_link_libraries(libprofiler PUBLIC libgpcp)
target_include_directories(libprofiler PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# Build the main profiler app
add_executable(profiler src/profiler.c)
target_link_libraries(profiler PRIVATE libprofiler libgpcp libnum libconvert libcompat m)
