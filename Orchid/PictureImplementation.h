#pragma once

#include "pch.h"

namespace oc {
	class PictureImplementation {
	public:
		//PictureImplementation(const std::string& picFile, int width, int height);
		virtual void Bind() = 0;
		virtual ~PictureImplementation() {};
		virtual int GetWidth() = 0;
		virtual int GetHeight() = 0;
	};
}