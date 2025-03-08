cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)

project(CLIEngine VERSION 0.3.0 LANGUAGES CXX)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/include/version.hpp.in"
    "${CMAKE_CURRENT_BINARY_DIR}/version.hpp"
    @ONLY
)

set(SOURCES
    src/CLIEngine/core.cpp
    src/CLIEngine/screens/navigation_screen.cpp
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
# core
    set(SAMPLES_CORE "${CMAKE_BINARY_DIR}/samples/core")
    file(MAKE_DIRECTORY ${SAMPLES_CORE})

    add_executable(colors src/samples/core/colors.cpp)
    target_link_libraries(colors PRIVATE cli_engine)
    set_target_properties(colors PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${SAMPLES_CORE})

    add_executable(hello_CLIEngine src/samples/core/hello_CLIEngine.cpp)
    target_link_libraries(hello_CLIEngine PRIVATE cli_engine)
    set_target_properties(hello_CLIEngine PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${SAMPLES_CORE})

    add_executable(sprite_CLIEngine src/samples/core/sprite_CLIEngine.cpp)
    target_link_libraries(sprite_CLIEngine PRIVATE cli_engine)
    set_target_properties(sprite_CLIEngine PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${SAMPLES_CORE})

    add_executable(sprite_smile_face src/samples/core/sprite_smile_face.cpp)
    target_link_libraries(sprite_smile_face PRIVATE cli_engine)
    set_target_properties(sprite_smile_face PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${SAMPLES_CORE})

# screens
    set(SAMPLES_SCREENS "${CMAKE_BINARY_DIR}/samples/screens")
    file(MAKE_DIRECTORY ${SAMPLES_SCREENS})

    add_executable(navigation_screen src/samples/screens/navigation_screen.cpp)
    target_link_libraries(navigation_screen PRIVATE cli_engine)
    set_target_properties(navigation_screen PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${SAMPLES_SCREENS})

# widgets
    set(SAMPLES_WIDGETS "${CMAKE_BINARY_DIR}/samples/widgets")
    file(MAKE_DIRECTORY ${SAMPLES_WIDGETS})

    add_executable(choices src/samples/widgets/choices.cpp)
    target_link_libraries(choices PRIVATE cli_engine)
    set_target_properties(choices PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${SAMPLES_WIDGETS})

    add_executable(combination_lock src/samples/widgets/combination_lock.cpp)
    target_link_libraries(combination_lock PRIVATE cli_engine)
    set_target_properties(combination_lock PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${SAMPLES_WIDGETS})

    add_executable(dice src/samples/widgets/dice.cpp)
    target_link_libraries(dice PRIVATE cli_engine)
    set_target_properties(dice PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${SAMPLES_WIDGETS})
endif()