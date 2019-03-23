#ifndef _WINDOW_H_
#define _WINDOW_H_

// System includes.
#include <iostream>

// External includes.
#include "glad/glad.h"
#include "GLFW/glfw3.h"

// My includes.
#include "TextureLoader.h"
#include "Camera.h"

class Window
{
public:
	Window(const int &width = 1920, const int &height = 1080, const char* title = "Magma Instance");
	~Window();
	int Initialize();

	bool Closed() const;
	void Update() const;
	void Clear() const;

	GLFWwindow& GetCurrentWindowRef() const { return *_window; };

private:
	// Callback functions.
	static void Framebuffer_Size_Callback(GLFWwindow* window, int width, int height);
	static void Mouse_Callback(GLFWwindow* window, double xpos, double ypos);
	static void Scroll_Callback(GLFWwindow* window, double xoffset, double yoffset);

private:
	int _screenWidth;
	int _screenHeight;
	const char* _screenTitle;

	bool _initialized = false;

	static bool _firstMouse;
	static float _lastX;
	static float _lastY;

	GLFWwindow* _window;
};

#endif // !_WINDOW_H_
