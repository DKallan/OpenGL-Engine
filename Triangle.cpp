#include "Triangle.h"

Triangle::Triangle(Shader* shader)
{
	_shader = shader;
}

Triangle::~Triangle()
{
	glDeleteVertexArrays(1, &_vao);
	glDeleteBuffers(1, &_vbo);
	glDeleteBuffers(1, &_ebo);
}

void Triangle::Initialize()
{
	glGenVertexArrays(1, &_vao);
	glGenBuffers(1, &_vbo);
	glGenBuffers(1, &_ebo);

	// Bind the Vertex Array Object, then bind and set the Vertex buffer and configure the vertex attributes.
	glBindVertexArray(_vao);

	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), _vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indices), _indices, GL_STATIC_DRAW);
	
	// Position.
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Unbind (might be unnecessary).
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Triangle::Draw()
{
	_shader->Use();
	glBindVertexArray(_vao); 
	glDrawElements(GL_TRIANGLES, sizeof(_indices) / sizeof(_indices[0]), GL_UNSIGNED_INT, 0);
}
