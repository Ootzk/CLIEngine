cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 11)

project(CLIEngine VERSION 0.1.0 LANGUAGES CXX)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/include/version.hpp.in"
    "${CMAKE_CURRENT_BINARY_DIR}/version.hpp"
    @ONLY
)

include_directories(include)

set(SOURCES
    src/CLIEngine_core.cpp
)

add_library(cli_engine ${SOURCES})
target_include_directories(cli_engine PUBLIC include)

# samples
add_executable(hello_CLIEngine src/samples/hello_CLIEngine.cpp)
target_link_libraries(hello_CLIEngine PRIVATE cli_engine)

add_executable(sprite_smile_face src/samples/sprite_smile_face.cpp)
target_link_libraries(sprite_smile_face PRIVATE cli_engine)

add_executable(sprite_CLIEngine src/samples/sprite_CLIEngine.cpp)
target_link_libraries(sprite_CLIEngine PRIVATE cli_engine)