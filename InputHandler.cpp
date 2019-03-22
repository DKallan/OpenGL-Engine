#include "InputHandler.h"

InputHandler::InputHandler(GLFWwindow* windowPtr, Camera* cameraPtr)
{
	_window = windowPtr;
	_camera = cameraPtr;
}

InputHandler::~InputHandler()
{
	// Release the pointer to the GLFW window.
	if (_window)
		_window = 0;

	// Release the pointer to the camera.
	if (_camera)
		_camera = 0;
}

void InputHandler::ProcessInput()
{
	// Escape exit button.
	if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(_window, true);

	// Camera movement.
}
