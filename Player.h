#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Entity.h"
#include "Window.h"

class Player : public Entity
{
private:
	glm::vec3 _velocity;

public:
	Player();

	void HandleInput(Window& window);

	void Update(float deltaTime);

private:
	void KeyBoardInput();
	void MouseInput(Window& window);
};

#endif // !_PLAYER_H_
