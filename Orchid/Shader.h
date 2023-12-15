#pragma once

#include "pch.h"
#include "utilities.h"
#include "ShaderImplementation.h"

namespace oc {
	class OC_API Shader {
	public:
		Shader(const std::string& vertexSFile, const std::string& fragmentSFile);
		Shader(std::string&& vertexSFile, std::string&& fragmentSFile);
		void Bind();
		void SetUniform2Ints(const std::string& uniformName, int val1, int val2);
		void SetUniform2Ints(std::string&& uniformName, int val1, int val2);

	private:
		std::unique_ptr<ShaderImplementation> mImplementation{ nullptr };
	};
}