cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)

project(CLIEngine VERSION 0.2.0 LANGUAGES CXX)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/include/version.hpp.in"
    "${CMAKE_CURRENT_BINARY_DIR}/version.hpp"
    @ONLY
)

set(SOURCES
    src/CLIEngine/core.cpp
)

add_library(cli_engine ${SOURCES})
target_include_directories(cli_engine
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

add_library(CLIEngine::CLIEngine ALIAS cli_engine)

# samples
if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    option(BUILD_SAMPLES "Build sample executables" ON)
else()
    option(BUILD_SAMPLES "Build sample executables" OFF)
endif()

if(BUILD_SAMPLES)
    add_executable(sample_hello_CLIEngine src/samples/hello_CLIEngine.cpp)
    target_link_libraries(sample_hello_CLIEngine PRIVATE cli_engine)

    add_executable(sample_sprite_smile_face src/samples/sprite_smile_face.cpp)
    target_link_libraries(sample_sprite_smile_face PRIVATE cli_engine)

    add_executable(sample_sprite_CLIEngine src/samples/sprite_CLIEngine.cpp)
    target_link_libraries(sample_sprite_CLIEngine PRIVATE cli_engine)

    add_executable(sample_screen_transition src/samples/screen_transition.cpp)
    target_link_libraries(sample_screen_transition PRIVATE cli_engine)

    add_executable(sample_colors src/samples/colors.cpp)
    target_link_libraries(sample_colors PRIVATE cli_engine)
endif()