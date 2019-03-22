#ifndef _TEXTURELOADER_H_
#define _TEXTURE_LOADER_H_

// System includes.
#include <iostream>

// External includes.
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class TextureLoader
{
public:
	static TextureLoader& Instance();
	~TextureLoader();

	TextureLoader(TextureLoader const &other) = delete;
	void operator=(TextureLoader const &other) = delete;

	unsigned int LoadTexture(const char* path) const;
	void SetWindowIcon(const char* path, GLFWwindow &_window) const;

private:
	TextureLoader();
};

#endif // !_TEXTURE_LOADER_H_
