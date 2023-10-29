#pragma once
#include "utilities.h"
#include "pch.h"
#include "GameWindow.h"

namespace oc {
	template <typename T>
	class OrchidApp {
	public:

		static void Init();
		static void RunInterface();

		void Run();
		virtual void OnUpdate();
		friend typename T;
	private:
		OrchidApp();
		inline static OrchidApp* sInstance{ nullptr };
		GameWindow mWindow;
		bool mShouldContinue{ true };
	};
}

#include "OrchidApp.cpp"
