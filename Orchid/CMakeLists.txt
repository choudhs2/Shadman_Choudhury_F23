set(HEADER_FILES 
	include/Orchid.h 
	OrchidApp.h 
	utilities.h
)

set(SOURCE_FILES 
	placeholder.cpp
)

add_library(Orchid SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Orchid PRIVATE pch.h)

add_definitions(
	-DOC_DEBUG=2
	-DOC_LIB
)

if(WIN32)
	add_definitions(-DOC_MSCPP)
elseif(LINUX)
	add_definitions(-DOC_LINUX)
elseif(APPLE)
	add_definitions(-DOC_APPLE)
endif()