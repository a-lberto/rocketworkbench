
file(GLOB SRCS "src/*.c")
add_library(libconvert STATIC ${SRCS})
set_target_properties(libconvert PROPERTIES OUTPUT_NAME convert)
target_include_directories(libconvert PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

if(BUILD_TESTING)
    add_executable(test_convert src/test.c)
    target_link_libraries(test_convert PRIVATE libconvert m)
    add_test(NAME test_convert COMMAND test_convert)
endif()
