cmake_minimum_required(VERSION 3.19)
project(RocketWorkbench C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

# Allow linking targets from other directories
cmake_policy(SET CMP0079 NEW)

# Common definitions
add_definitions(-DGCC)

# Enable Testing
enable_testing()

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Include all header paths
include_directories(
    libs/libcompat/include
    libs/libconvert/include
    libs/libnum/include
    libs/libcpropep/include
    libs/libthermo/include
    libs/liblrd/include
    libs/libmcp/include
    libs/librockflight/include
    libs/libsimulation
)

# --- LIBRARIES ---

add_library(libcompat STATIC libs/libcompat/compat.c libs/libcompat/getopt.c)
set_target_properties(libcompat PROPERTIES OUTPUT_NAME compat)

add_library(libconvert STATIC libs/libconvert/convert.c)
set_target_properties(libconvert PROPERTIES OUTPUT_NAME convert)

add_library(libnum STATIC 
    libs/libnum/lu.c libs/libnum/rk4.c libs/libnum/rkf.c libs/libnum/general.c 
    libs/libnum/print.c libs/libnum/sec.c libs/libnum/newton.c libs/libnum/ptfix.c 
    libs/libnum/sysnewton.c libs/libnum/trapeze.c libs/libnum/simpson.c libs/libnum/spline.c)
set_target_properties(libnum PROPERTIES OUTPUT_NAME num)

add_library(libcpropep STATIC 
    libs/libcpropep/equilibrium.c libs/libcpropep/print.c 
    libs/libcpropep/performance.c libs/libcpropep/derivative.c)
target_link_libraries(libcpropep PUBLIC libcompat libnum)
set_target_properties(libcpropep PROPERTIES OUTPUT_NAME cpropep)

add_library(libthermo STATIC libs/libthermo/load.c libs/libthermo/thermo.c)
target_link_libraries(libthermo PUBLIC libcpropep)
set_target_properties(libthermo PROPERTIES OUTPUT_NAME thermo)

add_library(liblrd STATIC libs/liblrd/lrd.c)
set_target_properties(liblrd PROPERTIES OUTPUT_NAME lrd)

add_library(libmcp STATIC libs/libmcp/mcp.c)
set_target_properties(libmcp PROPERTIES OUTPUT_NAME mcp)

add_library(librockflight STATIC 
    libs/librockflight/eom.c libs/librockflight/atmos.c libs/librockflight/aero.c 
    libs/librockflight/engine.c libs/librockflight/mass.c libs/librockflight/stage.c 
    libs/librockflight/rocket.c libs/librockflight/evaluate_function.c)
set_target_properties(librockflight PROPERTIES OUTPUT_NAME rockflight)

add_library(libsimulation STATIC 
    libs/libsimulation/lsode.cc libs/libsimulation/modeles.cc 
    libs/libsimulation/rk4.cc libs/libsimulation/rocket.cc libs/libsimulation/simulation.cc)
set_target_properties(libsimulation PROPERTIES OUTPUT_NAME simulation)

# --- APPLICATIONS ---

add_executable(cpropep apps/cpropep/cpropep.c)
target_link_libraries(cpropep PRIVATE libthermo libcpropep libnum libcompat m)
add_custom_command(TARGET cpropep POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/apps/cpropep/cpropep.conf
        $<TARGET_FILE_DIR:cpropep>/cpropep.conf
)

add_executable(prop apps/prop/prop.c)
target_link_libraries(prop PRIVATE libthermo libcpropep libcompat m)

add_executable(grain apps/gba/gba.c apps/gba/grain.c apps/gba/shape.c apps/gba/output.c)
target_link_libraries(grain PRIVATE m)

add_executable(lrd apps/lrd/main.c apps/lrd/lrd_load.c)
target_link_libraries(lrd PRIVATE liblrd libthermo libcpropep libnum m)

add_executable(mcp apps/mcp/modele.c apps/mcp/test.c)
target_link_libraries(mcp PRIVATE libmcp libthermo libcpropep libnum m)

# --- TESTS ---

add_executable(test_convert libs/libconvert/test.c)
target_link_libraries(test_convert PRIVATE libconvert m)
add_test(NAME test_convert COMMAND test_convert)

add_executable(test_num libs/libnum/test.c)
target_link_libraries(test_num PRIVATE libnum m)
add_test(NAME test_num COMMAND test_num)