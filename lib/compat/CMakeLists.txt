
file(GLOB SRCS "src/*.c")
add_library(libcompat STATIC ${SRCS})
target_include_directories(libcompat PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
