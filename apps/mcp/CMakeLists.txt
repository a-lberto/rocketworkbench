add_executable(mcp modele.c test.c)
target_link_libraries(mcp PRIVATE mcp_lib thermo cpropep_lib num m)
