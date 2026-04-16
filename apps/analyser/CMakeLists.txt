# Collect production source files from the src directory
file(GLOB SRCS "src/logic.c")

add_library(libanalyser STATIC ${SRCS})
set_target_properties(libanalyser PROPERTIES OUTPUT_NAME analyser)

target_link_libraries(libanalyser PUBLIC libgpcp libnum libconvert libcompat)
target_include_directories(libanalyser PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# Build the main analyser app
add_executable(analyser src/analyser.c)
target_link_libraries(analyser PRIVATE libanalyser libgpcp libnum libconvert libcompat m)
