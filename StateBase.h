#pragma once
#ifndef _STATE_BASE_H_
#define _STATE_BASE_H_

// My includes;
#include "Renderer.h"
#include "Engine.h"

class StateBase
{
protected:
	Engine* _engine;

public:
	StateBase(Engine& engine) : _engine(&engine) { }

	virtual ~StateBase() noexcept = default;

	virtual void HandleInput() = 0;

	virtual void Update(float deltaTime) = 0;
	virtual void Render(Renderer& renderer) = 0;
};

#endif