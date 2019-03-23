#include "Cube.h"

Cube::Cube(Shader* shader)
{
	_shader = shader;
}

Cube::~Cube()
{
	glDeleteVertexArrays(1, &_vao);
	glDeleteBuffers(1, &_vbo);
}

void Cube::Initialize()
{
	glGenVertexArrays(1, &_vao);
	glGenBuffers(1, &_vbo);

	// Bind the Vertex Array Object, then bind and set the Vertex buffer and configure the vertex attributes.
	glBindVertexArray(_vao);

	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), _vertices, GL_STATIC_DRAW);
	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// Normal attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
}

void Cube::AddTexture(const char* path)
{
	_texture = TextureLoader::Instance().LoadTexture(path);
}

void Cube::Draw()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _texture);

	_shader->Use();
	glBindVertexArray(_vao); 
	glDrawArrays(GL_TRIANGLES, 0, 36);
}
