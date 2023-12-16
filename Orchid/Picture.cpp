#include "pch.h"
#include "Picture.h"
#include "GLFWCode/OpenGLPicture.h"

namespace oc {
	Picture::Picture(const std::string& picFile) {
		//where we'll define our mImplementation, ie which shader implementation we're using
#ifdef OC_MSCPP
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(picFile) };
#elif OC_APPLE
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(picFile, width, height) };
#elif OC_LINUX
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(picFile, width, height) };
#endif
	}

	Picture::Picture(std::string&& picFile) {
		//where we'll define our mImplementation, ie which shader implementation we're using
#ifdef OC_MSCPP
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(std::move(picFile)) };
#elif OC_APPLE
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(picFile, width, height) };
#elif OC_LINUX
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(picFile, width, height) };
#endif
	}

	void Picture::Bind() {
		mImplementation->Bind();
	}

	int Picture::GetWidth() {
		return mImplementation->GetWidth();
	}

	int Picture::GetHeight() {
		return mImplementation->GetHeight();
	}
}