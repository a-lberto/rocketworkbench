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

# --- LIBRARIES ---

# libcompat
add_library(libcompat STATIC libs/libcompat/compat.c libs/libcompat/getopt.c)
target_include_directories(libcompat PUBLIC libs/libcompat/include)
set_target_properties(libcompat PROPERTIES OUTPUT_NAME compat)

# libconvert
add_library(libconvert STATIC libs/libconvert/convert.c)
target_include_directories(libconvert PUBLIC libs/libconvert/include)
set_target_properties(libconvert PROPERTIES OUTPUT_NAME convert)

# libnum
add_library(libnum STATIC 
    libs/libnum/lu.c libs/libnum/rk4.c libs/libnum/rkf.c libs/libnum/general.c 
    libs/libnum/print.c libs/libnum/sec.c libs/libnum/newton.c libs/libnum/ptfix.c 
    libs/libnum/sysnewton.c libs/libnum/trapeze.c libs/libnum/simpson.c libs/libnum/spline.c)
target_include_directories(libnum PUBLIC libs/libnum/include)
set_target_properties(libnum PROPERTIES OUTPUT_NAME num)

# libcpropep
add_library(libcpropep STATIC 
    libs/libcpropep/equilibrium.c libs/libcpropep/print.c 
    libs/libcpropep/performance.c libs/libcpropep/derivative.c)
target_include_directories(libcpropep PUBLIC libs/libcpropep/include)
target_link_libraries(libcpropep PUBLIC libcompat libnum)
set_target_properties(libcpropep PROPERTIES OUTPUT_NAME cpropep)

# libthermo
add_library(libthermo STATIC libs/libthermo/load.c libs/libthermo/thermo.c)
target_include_directories(libthermo PUBLIC libs/libthermo/include)
target_link_libraries(libthermo PUBLIC libcpropep)
set_target_properties(libthermo PROPERTIES OUTPUT_NAME thermo)

# liblrd
add_library(liblrd STATIC libs/liblrd/lrd.c)
target_include_directories(liblrd PUBLIC libs/liblrd/include)
set_target_properties(liblrd PROPERTIES OUTPUT_NAME lrd)

# libmcp
add_library(libmcp STATIC libs/libmcp/mcp.c)
target_include_directories(libmcp PUBLIC libs/libmcp/include)
set_target_properties(libmcp PROPERTIES OUTPUT_NAME mcp)

# librockflight
add_library(librockflight STATIC 
    libs/librockflight/eom.c libs/librockflight/atmos.c libs/librockflight/aero.c 
    libs/librockflight/engine.c libs/librockflight/mass.c libs/librockflight/stage.c 
    libs/librockflight/rocket.c libs/librockflight/evaluate_function.c)
target_include_directories(librockflight PUBLIC libs/librockflight/include)
set_target_properties(librockflight PROPERTIES OUTPUT_NAME rockflight)

# libsimulation
add_library(libsimulation STATIC 
    libs/libsimulation/lsode.cc libs/libsimulation/modeles.cc 
    libs/libsimulation/rk4.cc libs/libsimulation/rocket.cc libs/libsimulation/simulation.cc)
target_include_directories(libsimulation PUBLIC libs/libsimulation)
set_target_properties(libsimulation PROPERTIES OUTPUT_NAME simulation)

# --- APPLICATIONS ---

# cpropep app
add_executable(cpropep apps/cpropep/cpropep.c)
target_link_libraries(cpropep PRIVATE libthermo libcpropep libnum libcompat m)
add_custom_command(TARGET cpropep POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/apps/cpropep/cpropep.conf
        $<TARGET_FILE_DIR:cpropep>/cpropep.conf
)

# prop app
add_executable(prop apps/prop/prop.c)
target_link_libraries(prop PRIVATE libthermo libcpropep libcompat m)

# gba app
add_executable(grain apps/gba/gba.c apps/gba/grain.c apps/gba/shape.c apps/gba/output.c)
target_link_libraries(grain PRIVATE m)

# lrd app
add_executable(lrd apps/lrd/main.c apps/lrd/lrd_load.c)
target_link_libraries(lrd PRIVATE liblrd libthermo libcpropep libnum m)

# mcp app
add_executable(mcp apps/mcp/modele.c apps/mcp/test.c)
target_link_libraries(mcp PRIVATE libmcp libthermo libcpropep libnum m)
