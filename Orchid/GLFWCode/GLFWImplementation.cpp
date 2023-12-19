#include "pch.h"
#include "utilities.h"
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
		if (mWindow == NULL) {
			OC_ERROR("Failed to Create GLFW window");
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(mWindow);

		//make a user pointer that points to the Callbacks that we want to use
		glfwSetWindowUserPointer(mWindow, &mCallbacks);
		//next we set up the function that runs when we have a key press with the following lamda function
		//GLFW doesn't differentiate between press/release/hold but we can just check that in the lamda function
		//the function that it takes in is of type GLFWkeyfun (which is a function with the parameters seen here)
		glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int keycode, int scancode, int action, int mods) {
			if (action == GLFW_PRESS) {
				Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };
				KeyPressed e{ keycode };
				callbacks->keyPressedFunc(e);
			}
			else if (action == GLFW_RELEASE) {
				Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };
				KeyReleased e{ keycode };
				callbacks->keyReleasedFunc(e);
			}
			});
		//set glfw's window close callback to be the one we made as well
		//if you check GLFWwindowclosefun, you will see that it needs just one parameter, so we set it to be
		//this lamda function that takes that exact parameter, and this lamda will get the callbacks* from the
		//user pointer. Finally it will just use the windowCloseFunc that we gave it!
		glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window) {
			Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };
			callbacks->windowCloseFunc();
			});
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

	void GLFWImplementation::SetKeyPressedCallback(std::function<void(const KeyPressed&)>& callbackFunc) {
		mCallbacks.keyPressedFunc = callbackFunc;
	}
	void GLFWImplementation::SetKeyReleasedCallback(std::function<void(const KeyReleased&)>& callbackFunc) {
		mCallbacks.keyReleasedFunc = callbackFunc;
	}
	void GLFWImplementation::SetWindowCloseCallback(std::function<void()>& callbackFunc) {
		mCallbacks.windowCloseFunc = callbackFunc;
	}
}