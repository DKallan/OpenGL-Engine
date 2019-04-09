#pragma once
#ifndef _BASIC_SHADER_H_
#define _BASIC_SHADER_H_

#include "Shader.h"

class BasicShader : public Shader
{
private:
	GLuint _locationProjectionViewMatrix;
	GLuint _locationModelMatrix;

public:
	BasicShader(const char* vertexFile = "Resources/Shaders/Textured.vs", const char* fragmentFile = "Resources/Shaders/Textured.fs");

	void LoadProjectionViewMatrix(const glm::mat4& projectionViewMatrix);
	void LoadModelMatrix(const glm::mat4& matrix);

private:
	virtual void GetUniforms() override;
};

#endif // !_BASIC_SHADER_H_
