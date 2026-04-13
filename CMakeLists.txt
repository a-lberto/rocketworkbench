cmake_minimum_required(VERSION 3.19)
project(RocketWorkbench C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

# Allow linking targets from other directories
cmake_policy(SET CMP0079 NEW)

# Common definitions
add_definitions(-DGCC)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Include root libs for #include "libnum/include/num.h" style
include_directories(${CMAKE_SOURCE_DIR}/libs)

# Libraries
add_subdirectory(libs/libcompat)
add_subdirectory(libs/libconvert)
add_subdirectory(libs/libnum)
add_subdirectory(libs/libcpropep)
add_subdirectory(libs/libthermo)
add_subdirectory(libs/liblrd)
add_subdirectory(libs/libmcp)
add_subdirectory(libs/librockflight)
add_subdirectory(libs/libsimulation)

# Applications
add_subdirectory(apps/cpropep)
add_subdirectory(apps/prop)
# add_subdirectory(apps/analyser) # Depends on missing gpcp
add_subdirectory(apps/gba)
add_subdirectory(apps/lrd)
add_subdirectory(apps/mcp)
# add_subdirectory(apps/profiler) # Depends on missing gpcp
# add_subdirectory(apps/rockflight) # Depends on missing gpcp
