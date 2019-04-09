#pragma once
#ifndef _RENDERER_H_
#define _RENDERER_H_

// System includes.
#include <iostream>

// External includes.
#include "glm/glm.hpp"

// Other renderers.
#include "QuadRenderer.h"

// My includes.
#include "Window.h"

class Renderer
{
private:
	QuadRenderer _quadRenderer;

public:
	void DrawQuad(glm::vec3& position) const;

	void FinishRender(Window& window, const Camera& camera) const;
};

#endif // !_RENDERER_H_
