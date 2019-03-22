#include "TextureLoader.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

// Return the current Instance of the Texture Loader.
TextureLoader & TextureLoader::Instance()
{
	static TextureLoader instance;
	return instance;
}

unsigned int TextureLoader::LoadTexture(const char * path) const
{
	unsigned int textureID;
	glGenTextures(1, &textureID);

	int width, height, nrComponents;
	unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
	if (!data)
	{
		std::cout << "Texture failed to load at path: " << path << std::endl;
		stbi_image_free(data);

		return textureID;
	}

	GLenum format;
	switch (nrComponents)
	{
	case 1:
		format = GL_RED;
		break;
	case 3:
		format = GL_RGB;
		break;
	case 4:
		format = GL_RGBA;
		break;
	}

	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_image_free(data);

	return textureID;
}

void TextureLoader::SetWindowIcon(const char * path, GLFWwindow &_window) const
{
	GLFWimage icon; 
	
	icon.pixels = stbi_load(path, &icon.width, &icon.height, 0, 4); //rgba channels 
	if (!icon.pixels)
	{
		std::cout << "Failed to load image from path: " << path << std::endl;
		stbi_image_free(icon.pixels);
		return;
	}

	// Set the window icon and free the data.
	glfwSetWindowIcon(&_window, 1, &icon);
	stbi_image_free(icon.pixels);
	
	return;
}

TextureLoader::TextureLoader()
{
}

TextureLoader::~TextureLoader()
{
}