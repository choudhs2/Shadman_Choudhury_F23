cmake_minimum_required(VERSION 3.24)

project(Game)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT )

add_subdirectory(Orchid)
add_subdirectory(Game_SC)

