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
		SetWindowCloseCallback([this]() {DefaultWindowCloseHandler(); }); //A lamda function in C++?? Cool!
		//format: [what is visible](parameters) {code}
		//the above will set the default close function as the window close default!
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
		Shader shader("../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl");

		mNextFrameTime = std::chrono::steady_clock::now();

		while (mShouldContinue) {
			mRenderer.Clear();

			shader.Bind();
			shader.SetUniform2Ints("ScreenSize", mWindow.GetWidth(), mWindow.GetHeight());

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);//don't draw next frame until enough time passes
			//with the initial value for mNextFrameTime, we automatically draw the frame
			//with the following set value, we wait 1 frame time's worth before drawing the next one!
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

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

	template<typename T>
	void OrchidApp<T>::Draw(Unit& item) {
		mRenderer.Draw(item);
	}

	template<typename T>
	void OrchidApp<T>::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc) {
		mWindow.SetKeyPressedCallback(callbackFunc);
	}

	template<typename T>
	void OrchidApp<T>::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc) {
		mWindow.SetKeyReleasedCallback(callbackFunc);
	}

	template<typename T>
	void OrchidApp<T>::SetWindowCloseCallback(std::function<void()> callbackFunc) {
		mWindow.SetWindowCloseCallback(callbackFunc);
	}

	template<typename T>
	void OrchidApp<T>::DefaultWindowCloseHandler() {
		mShouldContinue = false;
	}

}