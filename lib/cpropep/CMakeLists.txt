
file(GLOB SRCS "src/*.c")

add_library(libcpropep STATIC ${SRCS})
set_target_properties(libcpropep PROPERTIES OUTPUT_NAME cpropep)

target_include_directories(libcpropep 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(libcpropep PUBLIC libcompat libnum)
