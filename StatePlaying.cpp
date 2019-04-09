#include "PlayingState.h"

StatePlaying::StatePlaying(Engine& engine) : StateBase(engine)
{
	Camera::Instance().HookEngity(_player);
}

void StatePlaying::HandleInput()
{
	_player.HandleInput(_engine->GetWindow());
}

void StatePlaying::Update(float deltaTime)
{
	_player.Update(deltaTime);
}

void StatePlaying::Render(Renderer& renderer)
{
	renderer.DrawQuad(glm::vec3(0,0,0));
}