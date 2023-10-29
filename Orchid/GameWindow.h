#pragma once
#include "pch.h"
#include "utilities.h"
#include "WindowImplementation.h"

namespace oc {
	class OC_API GameWindow {
	public:
		GameWindow();
		void Create(const std::string& name, int width, int height);
		int GetHeight() const;
		int GetWidth() const;
		//~GameWindow(); //default is probably fine for now
		void SwapBuffers();
		void PollEvents();

	private:
		std::unique_ptr<WindowImplementation> mImplementation{ nullptr };
	};
}
