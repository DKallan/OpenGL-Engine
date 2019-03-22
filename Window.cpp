#include "Window.h"

// Initialize static variables used by callbacks.
bool Window::_firstMouse = false;
float Window::_lastX = 0.0f;
float Window::_lastY = 0.0f;

Window::Window(const int & width, const int & height, const char * title)
{
	_screenWidth = width;
	_screenHeight = height;
	_screenTitle = title;
}

Window::~Window()
{
	if (_window)
	{
		glfwDestroyWindow(_window);
		_window = 0;
	}
}

int Window::Initialize()
{
	// Exit if already initialized.
	if (_initialized)
	{
		std::cout << "The window was already initialized!" << std::endl;
		return 1;
	}

	// Create a GLFW window.
	_window = glfwCreateWindow(_screenWidth, _screenHeight, _screenTitle, NULL, NULL);
	if (!_window)
	{
		std::cout << "Failed to create GLFW window." << std::endl;
		glfwTerminate();
		return -1;
	}

	// Make the window our current context and assign some callback functions.
	glfwMakeContextCurrent(_window);
	glfwSetFramebufferSizeCallback(_window, Framebuffer_Size_Callback);
	glfwSetCursorPosCallback(_window, Mouse_Callback);
	glfwSetScrollCallback(_window, Scroll_Callback);

	glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwSetWindowPos(_window, 50, 50);

	_initialized = true;
	return 0;
}

bool Window::Closed() const
{
	return glfwWindowShouldClose(_window);
}

void Window::Update() const
{
	glfwSwapBuffers(_window);
	glfwPollEvents();
}

// Resize Callback: Gets called whenever the window is resized and will change the viewport accordingly.
void Window::Framebuffer_Size_Callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Window::Mouse_Callback(GLFWwindow* window, double xpos, double ypos)
{
	if (_firstMouse)
	{
		_lastX = (float) xpos;
		_lastY = (float) ypos;
		_firstMouse = false;
	}

	float xoffset = (float) xpos - _lastX;
	float yoffset = _lastY - (float) ypos;
	
	_lastX = (float) xpos;
	_lastY = (float) ypos;
	
	//camera.ProcessMouseMovement(xoffset, yoffset);
}

void Window::Scroll_Callback(GLFWwindow * window, double xoffset, double yoffset)
{
	//camera.ProcessMouseScroll(yoffset);
}
