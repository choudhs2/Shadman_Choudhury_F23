#include "pch.h"
#include "utilities.h"
#include "OpenGLPicture.h"
#include "glad/glad.h"
#include "stb_image.h"

namespace oc {
	OpenGLPicture::OpenGLPicture(const std::string& picFile) {
		glGenTextures(1, &mTexture);
		glBindTexture(GL_TEXTURE_2D, mTexture);

		//set texture wrapping and filtering options (on currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//load and generate the texture:
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(picFile.c_str(), &mWidth, &mHeight, &mNumChannels, 0);
		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			OC_ERROR("Failed to load texture from file!");
		}
		stbi_image_free(data); //frees the data loaded into the image! (End of picture class code)
	}

	OpenGLPicture::OpenGLPicture(std::string&& picFile) {
		glGenTextures(1, &mTexture);
		glBindTexture(GL_TEXTURE_2D, mTexture);

		//set texture wrapping and filtering options (on currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//load and generate the texture:
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(picFile.c_str(), &mWidth, &mHeight, &mNumChannels, 0);
		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			OC_ERROR("Failed to load texture from file!");
		}
		stbi_image_free(data); //frees the data loaded into the image! (End of picture class code)
	}

	void OpenGLPicture::Bind() {
		glBindTexture(GL_TEXTURE_2D, mTexture);

	}

	int OpenGLPicture::GetWidth() {
		return mWidth;
	}

	int OpenGLPicture::GetHeight() {
		return mHeight;
	}

	OpenGLPicture::~OpenGLPicture() {
		glDeleteTextures(1, &mTexture);
	}

}