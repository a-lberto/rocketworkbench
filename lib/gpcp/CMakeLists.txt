
file(GLOB SRCS "src/*.c")

# Collect all production source files
add_library(libgpcp STATIC ${SRCS})

# PUBLIC: So apps linking to libgpcp can use <gpcp/gpcp.h>
# PRIVATE: So internal .c files can see headers in the src directory
target_include_directories(libgpcp 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if(BUILD_TESTING)
    add_executable(test_gpcp tests/test.c)
    target_link_libraries(test_gpcp PRIVATE libgpcp m)

    add_test(NAME test_gpcp COMMAND test_gpcp -f test.conf)
    
    set_tests_properties(test_gpcp PROPERTIES 
        WORKING_DIRECTORY "$<TARGET_FILE_DIR:test_gpcp>"
    )

    add_custom_command(TARGET test_gpcp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.conf
            $<TARGET_FILE_DIR:test_gpcp>/test.conf
    )
endif()