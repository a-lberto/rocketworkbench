cmake_minimum_required(VERSION 3.19)
project(RocketWorkbench C CXX)

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

# --- LIBRARIES ---

add_library_files(libcompat lib/compat)
set_target_properties(libcompat PROPERTIES OUTPUT_NAME compat)

add_library_files(libconvert lib/convert)
set_target_properties(libconvert PROPERTIES OUTPUT_NAME convert)

add_library_files(libnum lib/num)
set_target_properties(libnum PROPERTIES OUTPUT_NAME num)

add_library_files(libcpropep lib/cpropep)
target_link_libraries(libcpropep PUBLIC libcompat libnum)
set_target_properties(libcpropep PROPERTIES OUTPUT_NAME cpropep)

add_library_files(libthermo lib/thermo)
target_link_libraries(libthermo PUBLIC libcpropep)
set_target_properties(libthermo PROPERTIES OUTPUT_NAME thermo)

add_library_files(liblrd lib/lrd)
set_target_properties(liblrd PROPERTIES OUTPUT_NAME lrd)

add_library_files(libgpcp lib/gpcp)
set_target_properties(libgpcp PROPERTIES OUTPUT_NAME gpcp)

add_library_files(libmcp lib/mcp)
set_target_properties(libmcp PROPERTIES OUTPUT_NAME mcp)

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
add_custom_command(TARGET cpropep POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/apps/cpropep/cpropep.conf
        $<TARGET_FILE_DIR:cpropep>/cpropep.conf
)

add_app_target(prop apps/prop/prop.c)
target_link_libraries(prop PRIVATE libthermo libcpropep libcompat m)

add_app_target(grain apps/gba/gba.c) # Note: assumes common object handling if needed
target_sources(grain PRIVATE apps/gba/grain.c apps/gba/shape.c apps/gba/output.c)
target_link_libraries(grain PRIVATE m)

add_app_target(lrd apps/lrd/main.c)
target_sources(lrd PRIVATE apps/lrd/lrd_load.c)
target_link_libraries(lrd PRIVATE liblrd libthermo libcpropep libnum m)

add_app_target(mcp apps/mcp/modele.c)
target_sources(mcp PRIVATE apps/mcp/test.c)
target_link_libraries(mcp PRIVATE libmcp libthermo libcpropep libnum m)

add_app_target(analyser apps/analyser/analyser.c)
target_link_libraries(analyser PRIVATE libgpcp libnum libconvert libcompat m)
add_custom_command(TARGET analyser POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/apps/analyser/test.conf
        $<TARGET_FILE_DIR:analyser>/test.conf
)

# --- TESTS ---
enable_testing()
add_executable(test_convert lib/convert/test_convert.c)
target_link_libraries(test_convert PRIVATE libconvert m)
add_test(NAME test_convert COMMAND test_convert)

add_executable(test_num lib/num/test_num.c)
target_link_libraries(test_num PRIVATE libnum m)
add_test(NAME test_num COMMAND test_num)
