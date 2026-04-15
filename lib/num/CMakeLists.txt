
file(GLOB SRCS "src/*.c")
add_library(libnum STATIC ${SRCS})
set_target_properties(libnum PROPERTIES OUTPUT_NAME num)
target_include_directories(libnum PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

if(BUILD_TESTING)
    add_executable(test_num src/test.c)
    target_link_libraries(test_num PRIVATE libnum m)
    add_test(NAME test_num COMMAND test_num)
endif()
