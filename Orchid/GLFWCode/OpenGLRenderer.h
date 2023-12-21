#pragma once

#include "RendererImplementation.h"
#include "Unit.h"
#include "UnitSet.h"

namespace oc {
	class OpenGLRenderer : public RendererImplementation {
	public:
		//OpenGLRenderer();

		virtual void Init() override;

		virtual void Draw(int x, int y, Picture& pic) override;
		virtual void DrawScaled(int x, int y, float scale, Picture& pic) override;
		virtual void Draw(Unit& item) override;
		virtual void Draw(UnitSet& item) override;
		virtual void Clear() override;

		//~OpenGLRenderer();
	};
}