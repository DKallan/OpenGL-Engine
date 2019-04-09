#pragma once
#ifndef _BASIC_TEXTURE_H_
#define _BASIC_TEXTURE_H_

// External includes.
#include "GLFW/glfw3.h"

// System includes.
#include <string>

// My includes.
#include "NonCopyable.h"
#include "TextureLoader.h"

class BasicTexture : public NonCopyable
{
private:
	GLuint _id;

public:
	BasicTexture() = default;
	BasicTexture(const char* file);
	BasicTexture(const GLuint textureId) : _id(textureId) { };

	~BasicTexture();
	
	void BindTexture() const;
};

#endif // !_BASIC_TEXTURE_H_
