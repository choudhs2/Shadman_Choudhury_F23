#pragma once

#include "pch.h"
#include "utilities.h"
#include "RendererImplementation.h"
#include "Shader.h"
#include "Picture.h"
#include "Unit.h"
#include "UnitSet.h"

namespace oc {
	class OC_API Renderer {
	public:
		Renderer();
		void Init();
		void Draw(int x, int y, Picture& pic);
		void DrawScaled(int x, int y, float scale, Picture& pic);
		void Draw(Unit& item);
		void Draw(UnitSet& item);
		void Clear();

	private:
		std::unique_ptr<RendererImplementation> mImplementation{ nullptr };
	};
}