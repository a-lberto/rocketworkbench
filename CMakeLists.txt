cmake_minimum_required(VERSION 3.19)
project(RocketWorkbench C CXX)
add_compile_options(-Wall -Wextra -Werror -O3)

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

enable_testing()

# --- LIBRARIES ---
if(WIN32)
    add_subdirectory(external/syslog-win-0.3)
endif()
add_subdirectory(external/cgilib-0.7)
add_subdirectory(lib/compat)
add_subdirectory(lib/convert)
add_subdirectory(lib/num)
add_subdirectory(lib/cpropep)
add_subdirectory(lib/gpcp)

# --- APPLICATIONS ---
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
add_subdirectory(apps/rocket)