#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Shader.h"

class Triangle
{
private:
	unsigned int _vbo;
	unsigned int _vao;
	Shader* _shader;
	float* _vertices;

public:
	Triangle(float* vertices, Shader* shader);
	~Triangle();

	void Initialize();
	void Draw();

private:

};

#endif // !_TRIANGLE_H_
