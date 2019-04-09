#include "BasicShader.h"

BasicShader::BasicShader(const char * vertexFile, const char * fragmentFile) : Shader(vertexFile, fragmentFile)
{
	GetUniforms();
}

void BasicShader::LoadProjectionViewMatrix(const glm::mat4 & projectionViewMatrix)
{
	SetMat4("projViewMatrix", projectionViewMatrix);
}

void BasicShader::LoadModelMatrix(const glm::mat4 & matrix)
{
	SetMat4("modelMatrix", matrix);
}

void BasicShader::GetUniforms()
{
	Use();
	_locationProjectionViewMatrix = glGetUniformLocation(m_id, "projViewMatrix");
	_locationModelMatrix = glGetUniformLocation(m_id, "modelMatrix");
}
