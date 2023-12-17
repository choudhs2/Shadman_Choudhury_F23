#pragma once

#include "pch.h"
#include "Picture.h"

namespace oc {
	class RendererImplementation {
	public:
		virtual void Init() = 0;
		virtual void Draw(int x, int y, Picture& pic) = 0;
		virtual void DrawScaled(int x, int y, float scale, Picture& pic) = 0;
		virtual void Clear() = 0;
		virtual ~RendererImplementation() {};
	};
}