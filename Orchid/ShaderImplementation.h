#pragma once

#include "pch.h"

namespace oc {
	class ShaderImplementation {
	public:
		//ShaderImplementation(const std::string& vertexSFile, const std::string& fragmentSFile);
		virtual void Bind() = 0;
		virtual ~ShaderImplementation() {};
		virtual void SetUniform2Ints(const std::string& uniformName, int val1, int val2) = 0;
		virtual void SetUniform2Ints(std::string&& uniformName, int val1, int val2) = 0;
	};
}