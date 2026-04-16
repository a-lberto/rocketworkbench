# Collect production source files from the src directory
file(GLOB SRCS "src/grain.c" "src/output.c" "src/shape.c")

add_library(libgba STATIC ${SRCS})
set_target_properties(libgba PROPERTIES OUTPUT_NAME gba)

target_link_libraries(libgba PUBLIC libnum) # Add dependencies as needed
target_include_directories(libgba PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# Build the main grain app (gba)
add_executable(grain src/gba.c)
target_link_libraries(grain PRIVATE libgba m)
