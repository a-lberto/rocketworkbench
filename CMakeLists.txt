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
add_subdirectory(lib/num)
add_subdirectory(lib/cpropep)
add_subdirectory(lib/gpcp)
add_subdirectory(apps/rockflight)
add_subdirectory(apps/simulator)
add_subdirectory(apps/mcp)
add_subdirectory(apps/profiler)
add_subdirectory(apps/lrd)
add_subdirectory(apps/gba)
add_subdirectory(apps/analyser)
add_subdirectory(apps/prop)
add_subdirectory(apps/grainanalysis)
add_subdirectory(apps/cpropep)

# --- APPLICATIONS ---

# --- TESTS ---








