#include "pch.h"
#include "Shader.h"
#include "GLFWCode/OpenGLShader.h"

namespace oc {
	Shader::Shader(const std::string& vertexSFile, const std::string& fragmentSFile) {
        //where we'll define our mImplementation, ie which shader implementation we're using
#ifdef OC_MSCPP
        mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertexSFile, fragmentSFile) };
#elif OC_APPLE
        mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertexSFile, fragmentSFile) };
#elif OC_LINUX
        mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertexSFile, fragmentSFile) };
#endif
	}

    Shader::Shader(std::string&& vertexSFile, std::string&& fragmentSFile) {
        //where we'll define our mImplementation, ie which shader implementation we're using
#ifdef OC_MSCPP
        mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(std::move(vertexSFile), std::move(fragmentSFile)) };
#elif OC_APPLE
        mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertexSFile, fragmentSFile) };
#elif OC_LINUX
        mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertexSFile, fragmentSFile) };
#endif
    }

    void Shader::Bind() {
        mImplementation->Bind();
    }

    void Shader::SetUniform2Ints(const std::string& uniformName, int val1, int val2) {
        mImplementation->SetUniform2Ints(uniformName, val1, val2);
    }

    void Shader::SetUniform2Ints(std::string&& uniformName, int val1, int val2) {
        mImplementation->SetUniform2Ints(std::move(uniformName), val1, val2);
    }


}