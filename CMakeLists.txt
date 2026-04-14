cmake_minimum_required(VERSION 3.19)
project(RocketWorkbench C CXX)

# This generates build/compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

cmake_policy(SET CMP0079 NEW)
add_definitions(-DGCC)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Include library directories
include_directories(
    lib/compat lib/convert lib/num lib/cpropep lib/thermo
    lib/lrd lib/mcp lib/rockflight lib/simulation
)

# --- HELPER MACROS ---
macro(add_library_files libname folder)
    file(GLOB sources "${folder}/*.c" "${folder}/*.cc")
    add_library(${libname} STATIC ${sources})
    target_include_directories(${libname} PUBLIC ${folder})
endmacro()

enable_testing()

# --- LIBRARIES ---

add_subdirectory(lib/compat)
add_subdirectory(lib/convert)
set_target_properties(libconvert PROPERTIES OUTPUT_NAME convert)
add_subdirectory(lib/num)
set_target_properties(libnum PROPERTIES OUTPUT_NAME num)

add_library_files(libcpropep lib/cpropep)
target_link_libraries(libcpropep PUBLIC libcompat libnum)
set_target_properties(libcpropep PROPERTIES OUTPUT_NAME cpropep)

add_library_files(libthermo lib/thermo)
target_link_libraries(libthermo PUBLIC libcpropep)
set_target_properties(libthermo PROPERTIES OUTPUT_NAME thermo)

add_subdirectory(lib/gpcp)

add_library_files(librockflight lib/rockflight)
set_target_properties(librockflight PROPERTIES OUTPUT_NAME rockflight)

add_library_files(libsimulation lib/simulation)
set_target_properties(libsimulation PROPERTIES OUTPUT_NAME simulation)

# --- APPLICATIONS ---

macro(add_app_target appname source)
    add_executable(${appname} ${source})
endmacro()

add_app_target(cpropep apps/cpropep/cpropep.c)
target_link_libraries(cpropep PRIVATE libthermo libcpropep libnum libcompat m)

add_app_target(prop apps/prop/prop.c)
target_link_libraries(prop PRIVATE libthermo libcpropep libcompat m)

add_app_target(grain apps/gba/gba.c) # Note: assumes common object handling if needed
target_sources(grain PRIVATE apps/gba/grain.c apps/gba/shape.c apps/gba/output.c)
target_link_libraries(grain PRIVATE m)

add_app_target(lrd apps/lrd/main.c)
target_sources(lrd PRIVATE apps/lrd/lrd_load.c apps/lrd/lrd.c)
target_link_libraries(lrd PRIVATE libthermo libcpropep libnum m)

add_app_target(mcp apps/mcp/modele.c)
target_sources(mcp PRIVATE apps/mcp/test.c)
target_link_libraries(mcp PRIVATE libthermo libcpropep libnum m)

add_app_target(analyser apps/analyser/analyser.c)
target_link_libraries(analyser PRIVATE libgpcp libnum libconvert libcompat m)

add_app_target(rockflight apps/rockflight/rockflight.c)
target_sources(rockflight PRIVATE apps/rockflight/check.c apps/rockflight/parser.c apps/rockflight/print.c apps/rockflight/simulate.c)
target_include_directories(rockflight PRIVATE apps/rockflight lib/rockflight)
target_link_libraries(rockflight PRIVATE librockflight libgpcp libnum libcpropep libcompat m)

# --- TESTS ---








