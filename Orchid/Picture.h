#pragma once

#pragma once

#include "pch.h"
#include "utilities.h"
#include "PictureImplementation.h"

namespace oc {
	class OC_API Picture {
	public:
		Picture(const std::string& picFile);
		Picture(std::string&& picFile);
		void Bind();
		int GetWidth() const;
		int GetHeight() const;

	private:
		std::unique_ptr<PictureImplementation> mImplementation{ nullptr };
	};
}