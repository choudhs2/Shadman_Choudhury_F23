set(HEADER_FILES 
	include/Orchid.h 
	OrchidApp.h 
	utilities.h
	GLFWCode/GLFWImplementation.h
	GameWindow.h
	WindowImplementation.h
)

set(SOURCE_FILES 
	GLFWCode/GLFWImplementation.cpp
	GameWindow.cpp
)

add_definitions(-DOC_DEBUG=2)
add_definitions(-DOC_LIB)

include_directories(
	../glfw/include
	../Orchid
)

add_library(Orchid SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Orchid PRIVATE pch.h)

target_link_libraries(Orchid glfw)