#include "pch.h"
#include "GLFWImplementation.h"

namespace oc {
	GLFWImplementation::GLFWImplementation() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	void GLFWImplementation::Create(const std::string& name, int width, int height) {
		mWindow = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
	}

	int GLFWImplementation::GetHeight() const {
		int h{ 0 }, w{ 0 };
		glfwGetWindowSize(mWindow, &w, &h);
		return h;
	}

	int GLFWImplementation::GetWidth() const {
		int h{ 0 }, w{ 0 };
		glfwGetWindowSize(mWindow, &w, &h);
		return w;
	}

	void GLFWImplementation::SwapBuffers() {
		glfwSwapBuffers(mWindow);
	}

	void GLFWImplementation::PollEvents() {
		glfwPollEvents();
	}
	GLFWImplementation::~GLFWImplementation() {
		delete mWindow;
		mWindow = NULL;
	}
}