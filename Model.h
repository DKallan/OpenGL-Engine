#pragma once
#ifndef _MODEL_H_
#define _MODEL_H_

// External inclues.
#include <glad/glad.h>

// System includes.
#include <vector>

// My includes.
#include "NonCopyable.h"

class Model : public NonCopyable
{
private:
	GLuint _vao = 0;
	int _vboCount = 0;
	int _indicesCount = 0;
	std::vector<GLuint> _buffers;

public:
	Model() = default;
	Model(const std::vector<GLfloat>& vertexPositions, 
		  const std::vector<GLfloat>& textureCoords, 
		  const std::vector<GLuint>& indices);
	~Model();

	void AddData(const std::vector<GLfloat>& vertexPositions,
				 const std::vector<GLfloat>& textureCoords,
				 const std::vector<GLuint>& indices);

	void DeleteData();

	void AddVBO(int dimensions, const std::vector<GLfloat>& data);
	void BindVAO() const;

	int GetIndicesCount() const;

private:
	void AddEBO(const std::vector<GLuint>& indices);
};

#endif // !_MODEL_H_
