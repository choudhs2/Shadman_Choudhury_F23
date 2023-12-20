#pragma once
#include "utilities.h"
#include "pch.h"
#include "GameWindow.h"
#include "Picture.h"
#include "Renderer.h"
#include "Events.h"
#include "Unit.h"

namespace oc {

	constexpr int FPS{ 60 }; //target fps

	template <typename T>
	class OrchidApp {
	public:

		static void Init();
		static void RunInterface();

		void Run();
		virtual void OnUpdate();

		void Draw(int x, int y, Picture& pic);
		void DrawScaled(int x, int y, float scale, Picture& pic);

		void Draw(Unit& item);

		void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc);
		void SetWindowCloseCallback(std::function<void()> callbackFunc);

		void DefaultWindowCloseHandler();

		friend typename T;

	private:
		OrchidApp();
		inline static OrchidApp* sInstance{ nullptr };
		GameWindow mWindow;
		Renderer mRenderer;
		bool mShouldContinue{ true };

		std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000} / FPS };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}

#include "OrchidApp.cpp"
