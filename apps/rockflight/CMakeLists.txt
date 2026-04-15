
# Collect production source files from the src directory
file(GLOB SRCS "src/aero.c" "src/atmos.c" "src/engine.c" "src/eom.c" "src/evaluate_function.c" "src/mass.c" "src/rocket.c" "src/stage.c")

add_library(librockflight STATIC ${SRCS})
set_target_properties(librockflight PROPERTIES OUTPUT_NAME rockflight)

target_link_libraries(librockflight PUBLIC libgpcp)
target_include_directories(librockflight PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# Build the main rockflight app
add_executable(rockflight src/rockflight.c src/check.c src/parser.c src/print.c src/simulate.c)
target_link_libraries(rockflight PRIVATE librockflight libcpropep libnum libcompat m)

# Build the GUI viewer app if X11 is found
find_package(X11)
if(X11_FOUND)
    add_executable(viewer src/viewer.c)
    target_link_libraries(viewer PRIVATE librockflight ${X11_LIBRARIES} m)
endif()

