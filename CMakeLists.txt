cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)

project(CLIEngine VERSION 0.2.0 LANGUAGES CXX)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/include/version.hpp.in"
    "${CMAKE_CURRENT_BINARY_DIR}/version.hpp"
    @ONLY
)

set(SOURCES
    src/CLIEngine_core.cpp
    src/CLIEngine_screen.cpp
)

add_library(cli_engine ${SOURCES})
target_include_directories(cli_engine
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

add_library(CLIEngine::CLIEngine ALIAS cli_engine)

# samples
option(BUILD_SAMPLES "Build sample executables" ON)
if(BUILD_SAMPLES)
    add_executable(hello_CLIEngine src/samples/hello_CLIEngine.cpp)
    target_link_libraries(hello_CLIEngine PRIVATE cli_engine)

    add_executable(sprite_smile_face src/samples/sprite_smile_face.cpp)
    target_link_libraries(sprite_smile_face PRIVATE cli_engine)

    add_executable(sprite_CLIEngine src/samples/sprite_CLIEngine.cpp)
    target_link_libraries(sprite_CLIEngine PRIVATE cli_engine)

    add_executable(screen_transition src/samples/screen_transition.cpp)
    target_link_libraries(screen_transition PRIVATE cli_engine)

    add_executable(colors src/samples/colors.cpp)
    target_link_libraries(colors PRIVATE cli_engine)
endif()