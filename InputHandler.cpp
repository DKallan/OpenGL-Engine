#include "InputHandler.h"

InputHandler::InputHandler(GLFWwindow &windowRef, Camera &cameraRef)
{
	_window = &windowRef;
	_camera = &cameraRef;
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

void InputHandler::ProcessInput(float deltaTime)
{
	// Escape exit button.
	if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(_window, true);

	// Camera movement.
	if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS)
		_camera->ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS)
		_camera->ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS)
		_camera->ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS)
		_camera->ProcessKeyboard(RIGHT, deltaTime);
	if (glfwGetKey(_window, GLFW_KEY_E) == GLFW_PRESS)
		_camera->ProcessKeyboard(UP, deltaTime);
	if (glfwGetKey(_window, GLFW_KEY_Q) == GLFW_PRESS)
		_camera->ProcessKeyboard(DOWN, deltaTime);
}
