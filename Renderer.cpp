#include "Renderer.h"

void Renderer::DrawQuad(glm::vec3 & position) const
{
	_quadRenderer.Add(position);
}

void Renderer::FinishRender(Window& window, const Camera& camera) const
{
	glClearColor(0.1, 0.5, 1.0, 1.0);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	
	_quadRenderer.RenderQuads();
	window.Display();
}
