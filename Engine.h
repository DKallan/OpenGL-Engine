#ifndef _ENGINE_H_
#define _ENGINE_H_

// System includes.
#include <string.h>

// My includes.
#include "Window.h"
#include "InputHandler.h"
#include "Triangle.h"

class Engine
{
private:
	Window* _window;
	Camera* _camera;
	InputHandler* _inputHandler;

	bool _initialized = false;

	float _deltaTime;
	float _lastFrame;

public:
	Engine();
	~Engine();

	int Initialize();
	int Run();

	void UpdateTime();
	void Draw();

private:
	static void Error_Callback(int error, const char* description);
};

#endif // !_ENGINE_H_