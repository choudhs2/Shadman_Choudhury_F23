#include "pch.h"
#include "OrchidApp.h"
#include "utilities.h"
#include "Shader.h"
#include "Picture.h"
#include "Renderer.h"

namespace oc {
	template <typename T>
	OrchidApp<T>::OrchidApp(){
		mWindow.Create("Game SC", 800, 600);
		mRenderer.Init();
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
		//// Shaders ////
		
		Shader shader("../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl");

		//// Textures ////
		Picture pic("../Assets/Pictures/test.png");

		while (mShouldContinue) {
			mRenderer.Clear();

			shader.Bind();
			shader.SetUniform2Ints("ScreenSize", mWindow.GetWidth(), mWindow.GetHeight());

			DrawScaled(100, 200, 0.5, pic);
			OnUpdate();

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
	}

	template<typename T>
	void OrchidApp<T>::OnUpdate() {
		//nothing here! The User will implement this!
	}

	template<typename T>
	void OrchidApp<T>::Draw(int x, int y, Picture& pic) {
		mRenderer.Draw(x, y, pic);
	}

	template<typename T>
	void OrchidApp<T>::DrawScaled(int x, int y, float scale, Picture& pic) {
		mRenderer.DrawScaled(x, y, scale, pic);
	}
}