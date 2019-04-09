#pragma once
#ifndef _QUAD_RENDERER_H_
#define _QUAD_RENDERER_H_

// External includes.
#include "glm/glm.hpp"

// System includes.
#include <vector>

// My includes.
#include "Model.h"
#include "BasicTexture.h"
#include "Shader.h"
#include "camera.h"

class QuadRenderer
{
private:
	std::vector<glm::vec3> _quads;
	Model _quadModel;
	Shader _shader;
	BasicTexture _basicTexture;

public:
	QuadRenderer();
	~QuadRenderer();

	void Add(const glm::vec3& position) const;

	void RenderQuads(const Camera& camera);
};

#endif // !_QUAD_RENDERER_H_
