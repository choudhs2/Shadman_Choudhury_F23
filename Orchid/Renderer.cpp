#include "pch.h"
#include "Renderer.h"
#include "GLFWCode/OpenGLRenderer.h"

namespace oc {
	oc::Renderer::Renderer() {
		//where we'll define our mImplementation, ie which shader implementation we're using
#ifdef OC_MSCPP
		mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif OC_APPLE
		mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif OC_LINUX
		mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#endif
	}

	void Renderer::Init() {
		mImplementation->Init();
	}

	void Renderer::Draw(int x, int y, Picture& pic) {
		mImplementation->Draw(x, y, pic);
	}

	void Renderer::DrawScaled(int x, int y, float scale, Picture& pic) {
		mImplementation->DrawScaled(x, y, scale, pic);
	}

	void Renderer::Clear() {
		mImplementation->Clear();
	}

}