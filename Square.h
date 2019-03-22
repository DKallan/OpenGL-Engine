#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Shader.h"

class Square
{
private:
	unsigned int _vbo;
	unsigned int _vao;
	Shader* _shader;
	float* _vertices;

public:
	Square(float* vertices, Shader* shader);
	~Square();

	void Initialize();
	void Draw();

private:

};

#endif // !_TRIANGLE_H_
