#version 330 core

in vec2 TexCoord;
uniform sampler2D picture;

out vec4 FragShader;

void main() {
	FragShader = texture(picture, TexCoord);
}