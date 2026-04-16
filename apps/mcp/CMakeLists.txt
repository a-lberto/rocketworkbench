# Collect production source files from the src directory
file(GLOB SRCS "src/modele.c")

add_library(libmcp STATIC ${SRCS})
set_target_properties(libmcp PROPERTIES OUTPUT_NAME mcp)

target_link_libraries(libmcp PUBLIC libcpropep libnum)
target_include_directories(libmcp PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# Build the main mcp app (chamber pressure evaluation)
add_executable(mcp src/mcp.c)
target_link_libraries(mcp PRIVATE libmcp libcpropep libnum libcompat m)

# Build the transient test app
add_executable(mcp-test src/test.c)
target_link_libraries(mcp-test PRIVATE libmcp libcpropep libnum libcompat m)
