cmake_minimum_required(VERSION 3.24)

project(Game)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

if(WIN32)
	add_definitions(-DOC_MSCPP)
elseif(LINUX)
	add_definitions(-DOC_LINUX)
elseif(APPLE)
	add_definitions(-DOC_APPLE)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Game_SC)

add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(stbi)
add_subdirectory(Orchid)
add_subdirectory(Game_SC)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR})
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)