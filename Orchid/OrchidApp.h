#pragma once
#include "utilities.h"
#include "pch.h"
#include "GameWindow.h"
#include "Picture.h"
#include "Renderer.h"

namespace oc {
	template <typename T>
	class OrchidApp {
	public:

		static void Init();
		static void RunInterface();

		void Run();
		virtual void OnUpdate();

		void Draw(int x, int y, Picture& pic);
		void DrawScaled(int x, int y, float scale, Picture& pic);

		friend typename T;

	private:
		OrchidApp();
		inline static OrchidApp* sInstance{ nullptr };
		GameWindow mWindow;
		Renderer mRenderer;
		bool mShouldContinue{ true };
	};
}

#include "OrchidApp.cpp"
