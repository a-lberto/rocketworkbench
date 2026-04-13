add_library(mcp_lib STATIC mcp.c)
target_include_directories(mcp_lib PUBLIC include)
set_target_properties(mcp_lib PROPERTIES OUTPUT_NAME mcp)
