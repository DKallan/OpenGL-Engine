#include "Model.h"

Model::Model(const std::vector<GLfloat>& vertexPositions, const std::vector<GLfloat>& textureCoords, const std::vector<GLuint>& indices)
{
	AddData(vertexPositions, textureCoords, indices);
}

Model::~Model()
{
	DeleteData();
}

void Model::AddData(const std::vector<GLfloat>& vertexPositions, const std::vector<GLfloat>& textureCoords, const std::vector<GLuint>& indices)
{
	if (_vao != 0)
		DeleteData();

	_indicesCount = indices.size();

	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	AddVBO(3, vertexPositions);
	AddVBO(2, textureCoords);
	AddEBO(indices);
}

void Model::DeleteData()
{
	glDeleteVertexArrays(1, &_vao);
	glDeleteBuffers(_buffers.size(), _buffers.data());

	_buffers.clear();

	_vboCount = 0;
	_vao = 0;
	_indicesCount = 0;
}

void Model::AddVBO(int dimensions, const std::vector<GLfloat>& data)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), data.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(_vboCount, dimensions, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);

	glEnableVertexAttribArray(_vboCount++);

	_buffers.push_back(vbo);
}

void Model::BindVAO() const
{
	glBindVertexArray(_vao);
}

int Model::GetIndicesCount() const
{
	return _indicesCount;
}

void Model::AddEBO(const std::vector<GLuint>& indices)
{
	GLuint ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
}
