#pragma once
#include "PictureImplementation.h"

namespace oc {
	class OpenGLPicture : public PictureImplementation {
	public:
		OpenGLPicture(const std::string& picFile);
		OpenGLPicture(std::string&& picFile);
		virtual void Bind() override;

		virtual int GetWidth() override;
		virtual int GetHeight() override;

		~OpenGLPicture();
	private:
		int mWidth, mHeight, mNumChannels;
		unsigned int mTexture{ 0 };
	};
}