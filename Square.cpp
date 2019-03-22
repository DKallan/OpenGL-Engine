#include "Square.h"

Square::Square(float* vertices, Shader* shader)
{
	_vertices = vertices;
	_shader = shader;
}

Square::~Square()
{
}

void Square::Initialize()
{
	glGenBuffers(1, &_vbo);
	glGenVertexArrays(1, &_vao);

	glBindVertexArray(_vao);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), _vertices, GL_STATIC_DRAW);

	// Position.
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	// Color.
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void Square::Draw()
{
	_shader->Use();
	glBindVertexArray(_vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
