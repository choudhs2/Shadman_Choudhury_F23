#pragma once
#include "utilities.h"
#include "pch.h"

namespace oc {
	template <typename T>
	class OC_API OrchidApp {
	public:

		static void Init();
		static void RunInterface();

		void Run();
		virtual void OnUpdate();
		friend typename T;
	private:
		OrchidApp();
		inline static OrchidApp* sInstance{ nullptr };
		bool mShouldContinue{ true };
	};
}

#include "OrchidApp.cpp"
