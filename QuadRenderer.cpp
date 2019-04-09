#include "QuadRenderer.h"

QuadRenderer::QuadRenderer()
{
	_basicTexture = BasicTexture("Resources/Assets/texture_stone.png");
	_shader = Shader("Resources/Shaders/Textured.vs", "Resources/Shaders/Textured.fs");

	_quadModel = Model();
	_quadModel.AddData(
		{
			-0.5,  0.5, 0,
			 0.5,  0.5, 0,
			 0.5, -0.5, 0, 
			-0.5, -0.5, 0
		},
		{
			0, 1,
			1, 1,
			1, 0, 
			0, 0
		},
		{
			0, 1, 2,
			2, 3, 0
		});
}

QuadRenderer::~QuadRenderer()
{

}

void QuadRenderer::Add(const glm::vec3 & position) const
{
	_quads.push_back(position);
}

void QuadRenderer::RenderQuads(const Camera & camera)
{
	_shader.Use();
	_quadModel.BindVAO();
	_basicTexture.BindTexture();

	_shader.LoadProjectionViewMatrix(camera.GetProjectionViewMatrix());

	for (const glm::vec3& quad : _quads)
	{
		_shader.LoadModelMatrix(MakeModelMatrix({ quad, glm::vec3(0, 0, 0) }));

		glDrawElements(GL_TRIANGLES, _quadModel.GetIndicesCount(), GL_UNSIGNED_INT, nullptr);
	}

	_quads.clear();
}
