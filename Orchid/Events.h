#pragma once
#include "utilities.h"

namespace oc {
	class OC_API KeyPressed {
	public:
		KeyPressed(int kCode);
		int GetKeyCode() const;
	private:
		int mKeyCode;
	};

	class OC_API KeyReleased {
	public:
		KeyReleased(int kCode);
		int GetKeyCode() const;
	private:
		int mKeyCode;
	};

	class OC_API WindowCLosed {

	};
}