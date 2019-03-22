#ifndef _SHADER_H_
#define _SHADER_H_

// System includes.
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

// External includes.
#include <glad/glad.h>
#include <glm/glm.hpp>

class Shader
{
public:
	unsigned int ID;

public:
	Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath);
	~Shader();

	void Use();
	void SetBool(const std::string&, bool) const;
	void SetInt(const std::string&, int) const;
	void SetFloat(const std::string&, float) const;
	void SetVec2(const std::string&, const glm::vec2&) const;
	void SetVec2(const std::string&, float, float) const;
	void SetVec3(const std::string&, const glm::vec3&) const;
	void SetVec3(const std::string&, float, float, float) const;
	void SetVec4(const std::string&, const glm::vec4&) const;
	void SetVec4(const std::string&, float, float, float, float) const;
	void SetMat2(const std::string&, const glm::mat2&) const;
	void SetMat3(const std::string&, const glm::mat3&) const;
	void SetMat4(const std::string&, const glm::mat4&) const;

private:
	void CheckCompileErrors(GLuint, std::string);
};

#endif // !_SHADER_H_