#include "pch.h"
#include "utilities.h"
#include "OpenGLShader.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace oc {
	OpenGLShader::OpenGLShader(const std::string& vertexSF, const std::string& fragmentSF) {

		std::string readVertShader = ReadWholeFile(vertexSF);
		const char* vertexShaderSource = readVertShader.c_str();
		std::string readFragShader = ReadWholeFile(fragmentSF);
		const char* fragmentShaderSource = readFragShader.c_str();

		unsigned int vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			OC_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
		}

		unsigned int fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			OC_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
		}

		mShaderProgram = glCreateProgram();
		glAttachShader(mShaderProgram, vertexShader);
		glAttachShader(mShaderProgram, fragmentShader);
		glLinkProgram(mShaderProgram);

		glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(mShaderProgram, 512, NULL, infoLog);
			OC_ERROR("Linking FAILED with message: " << infoLog);
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	OpenGLShader::OpenGLShader(std::string&& vertexSF, std::string&& fragmentSF) {

		std::string readVertShader = ReadWholeFile(std::move(vertexSF));
		const char* vertexShaderSource = readVertShader.c_str();
		std::string readFragShader = ReadWholeFile(std::move(fragmentSF));
		const char* fragmentShaderSource = readFragShader.c_str();

		unsigned int vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			OC_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
		}

		unsigned int fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			OC_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
		}

		mShaderProgram = glCreateProgram();
		glAttachShader(mShaderProgram, vertexShader);
		glAttachShader(mShaderProgram, fragmentShader);
		glLinkProgram(mShaderProgram);

		glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(mShaderProgram, 512, NULL, infoLog);
			OC_ERROR("Linking FAILED with message: " << infoLog);
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void OpenGLShader::Bind() {
		glUseProgram(mShaderProgram);
	}

	void OpenGLShader::SetUniform2Ints(const std::string& uniformName, int val1, int val2) {
		glUseProgram(mShaderProgram);
		GLint location = glGetUniformLocation(mShaderProgram, uniformName.c_str());
		glUniform2i(location, val1, val2);
	}

	void OpenGLShader::SetUniform2Ints(std::string&& uniformName, int val1, int val2) {
		glUseProgram(mShaderProgram);
		GLint location = glGetUniformLocation(mShaderProgram,uniformName.c_str());
		glUniform2i(location, val1, val2);
	}

	OpenGLShader::~OpenGLShader() {
		glDeleteProgram(mShaderProgram); //let opengl deal with deleting it!
	}

	std::string OpenGLShader::ReadWholeFile(const std::string& filename) {
		std::ifstream inputFile(filename);
		std::string result;
		std::string nextLine;
		while (inputFile) {
			std::getline(inputFile, nextLine); //does not include \n
			if (!inputFile) { break; } //to prevent copying the last line
			result += nextLine;
			result += "\n";
		}
		return result;
	}

	std::string OpenGLShader::ReadWholeFile(std::string&& filename) {
		std::ifstream inputFile(std::move(filename));
		std::string result;
		std::string nextLine;
		while (inputFile) {
			std::getline(inputFile, nextLine); //does not include \n
			if (!inputFile) { break; } //to prevent copying the last line
			result += nextLine;
			result += "\n";
		}
		return result;
	}
}