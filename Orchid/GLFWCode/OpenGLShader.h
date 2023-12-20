#pragma once
#include "ShaderImplementation.h"

namespace oc {
	class OpenGLShader : public ShaderImplementation {
	public:
		OpenGLShader(const std::string& vertexSF, const std::string& fragmentSF);
		OpenGLShader(std::string&& vertexSF, std::string&& fragmentSF);
		virtual void Bind() override;

		virtual void SetUniform2Ints(const std::string& uniformName, int val1, int val2) override;
		virtual void SetUniform2Ints(std::string&& uniformName, int val1, int val2) override;

		~OpenGLShader();
	private:
		unsigned int mShaderProgram{ 0 };

		std::string ReadWholeFile(const std::string& filename);
		std::string ReadWholeFile(std::string&& filename);
	};
}