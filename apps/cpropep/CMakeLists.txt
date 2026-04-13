add_executable(cpropep cpropep.c)
target_link_libraries(cpropep PRIVATE thermo cpropep_lib num compat m)

# Copy config file to output directory
add_custom_command(TARGET cpropep POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/cpropep.conf
        $<TARGET_FILE_DIR:cpropep>/cpropep.conf
)
