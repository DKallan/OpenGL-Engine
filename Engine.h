#ifndef _ENGINE_H_
#define _ENGINE_H_

// My includes.
#include "Window.h"
#include "InputHandler.h"

class Engine
{
private:
	Window* _window;
	Camera* _camera;
	InputHandler* _inputHandler;

	bool _initialized = false;

public:
	Engine();
	~Engine();

	int Initialize();
	int Run();

private:
	static void Error_Callback(int error, const char* description);
};

#endif // !_ENGINE_H_
