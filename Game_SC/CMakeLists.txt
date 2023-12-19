set(HEADER_FILES 
	MyGame.h
)

set(SOURCE_FILES 
	MyGame.cpp
	main.cpp
)

add_executable(Game_SC ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(Game_SC Orchid)

include_directories(../Orchid/include)
