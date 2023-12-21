set(HEADER_FILES 
	include/Orchid.h 
	OrchidApp.h 
	Events.h
	GameWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
	GLFWCode/OpenGLPicture.h
	GLFWCode/OpenGLRenderer.h
	GLFWCode/OpenGLShader.h
	Picture.h
	PictureImplementation.h
	Renderer.h
	RendererImplementation.h
	Shader.h
	ShaderImplementation.h
	Unit.h
	utilities.h
	UnitSet.h
)

set(SOURCE_FILES 
	GLFWCode/GLFWImplementation.cpp
	GameWindow.cpp
	Events.cpp
	GLFWCode/OpenGLPicture.cpp
	GLFWCode/OpenGLRenderer.cpp
	GLFWCode/OpenGLShader.cpp
	Picture.cpp
	Renderer.cpp
	Shader.cpp
	Unit.cpp
	UnitSet.cpp
)

add_definitions(-DOC_DEBUG=2)
add_definitions(-DOC_LIB)

include_directories(
	../glfw/include
	../Orchid
	../glad/include
	../stbi
)

add_library(Orchid SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Orchid PRIVATE pch.h)

target_link_libraries(Orchid glfw)
target_link_libraries(Orchid glad)
target_link_libraries(Orchid stbi)
