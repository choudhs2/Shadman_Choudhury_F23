set(HEADER_FILES 
)

set(SOURCE_FILES 
	main.cpp
)

add_executable(Game_SC ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(Game_SC Orchid)

include_directories(../Orchid/include)
