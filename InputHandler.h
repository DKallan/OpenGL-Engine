#pragma once
#ifndef _INPUT_HANDLER_H_
#define _INPUT_HANDLER_H_

// My includes.
#include "Camera.h"

// External includes.
#include "GLFW/glfw3.h"

class InputHandler
{
public:
	InputHandler(GLFWwindow &windowRef, Camera &cameraRef);
	~InputHandler();

	void ProcessInput(float deltaTime);

private:
	GLFWwindow* _window;
	Camera* _camera;
};

#endif // !_INPUT_HANDLER_H_
