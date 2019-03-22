#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Shader.h"

class Triangle
{
private:
	unsigned int _vbo;
	unsigned int _vao;
	unsigned int _ebo;
	Shader* _shader;

	float _vertices[12] = {
		 0.5f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};

	unsigned int _indices[6] = {
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

public:
	Triangle(Shader* shader);
	~Triangle();

	void Initialize();
	void Draw();

private:

};

#endif // !_TRIANGLE_H_
