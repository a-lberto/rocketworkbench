
# Find FLEX in the path
find_package(FLEX REQUIRED)
FLEX_TARGET(MotorParser src/motor.l ${CMAKE_CURRENT_BINARY_DIR}/motor_lexer.cc)

# Collect production source files from the src directory
file(GLOB SRCS "src/*.cc")

add_library(libsimulation STATIC ${SRCS} ${FLEX_MotorParser_OUTPUTS})

target_link_libraries(libsimulation PUBLIC libnum)
target_include_directories(libsimulation PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# Build the main simulator app
add_executable(simulator src/c++rocket.cc)
target_link_libraries(simulator PRIVATE libsimulation m)
