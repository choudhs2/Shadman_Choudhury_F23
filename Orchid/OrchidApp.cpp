#include "pch.h"
#include "OrchidApp.h"

namespace oc {
	template <typename T>
	OrchidApp<T>::OrchidApp(){
	}

	template<typename T>
	void OrchidApp<T>::Init() {
		if (sInstance == nullptr) {
			sInstance = new T;
		}
	}

	template<typename T>
	void OrchidApp<T>::RunInterface() {
		sInstance->Run();
	}

	template <typename T>
	void OrchidApp<T>::Run() {
		mWindow.Create("Game_SC", 800, 600);
		while (mShouldContinue) {
			OnUpdate();
			mWindow.SwapBuffers();
			mWindow.PollEvents();
			//glfwSwapBuffers(window);
			//glfwPollEvents();
		}
	}
	template<typename T>
	void OrchidApp<T>::OnUpdate()
	{
	}
}