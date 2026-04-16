# Collect production source files from the src directory
file(GLOB SRCS "src/lrd.c" "src/load.c")

add_library(liblrd STATIC ${SRCS})
set_target_properties(liblrd PROPERTIES OUTPUT_NAME lrd)

target_link_libraries(liblrd PUBLIC libcpropep libnum)
target_include_directories(liblrd PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# Build the main lrd app
add_executable(lrd src/main.c)
target_link_libraries(lrd PRIVATE liblrd libcpropep libnum libcompat m)
