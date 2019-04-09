#pragma once
#ifndef _PLAYING_STATE_H_
#define _PLAYING_STATE_H_

#include "Player.h"
#include "StateBase.h"

class StatePlaying : public StateBase
{
private:
	Player _player;

public:
	StatePlaying(Engine& engine);

	void HandleInput();

	void Update(float deltaTime);

	void Render(Renderer& renderer);
};

#endif