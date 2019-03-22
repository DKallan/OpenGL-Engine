#include "Engine.h"

static const int WIDTH = 1280;
static const int HEIGHT = 720;

// Constructor.
Engine::Engine()
{
	// Initialize GLFW for OpenGL version 3.
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwSetErrorCallback(Error_Callback);
}

// Destructor.
Engine::~Engine()
{
	if (_window)
	{
		delete _window;
		_window = 0;
	}

	if (_camera)
	{
		delete _camera;
		_camera = 0;
	}

	if (_inputHandler)
	{
		delete _inputHandler;
		_inputHandler = 0;
	}

	glfwTerminate();
}

int Engine::Initialize()
{
	_window = new Window(WIDTH, HEIGHT, "Minecraft Magma Edition");
	int result = _window->Initialize();
	if (result)
	{
		std::cout << "Something went wrong during WINDOW initialization. Error: " << result << std::endl;
		return result;
	}

	_camera = new Camera();
	if (!_camera)
	{
		std::cout << "Failed to create Camera object." << std::endl;
		return -3;
	}

	_inputHandler = new InputHandler(_window->GetCurrentWindowPtr(), _camera);
	if (!_inputHandler)
	{
		std::cout << "Failed to create InputHandler object." << std::endl;
		return -4;
	}

	return 0;
}

// Main execution point.
int Engine::Run()
{
	// Game loop.
	while (!_window->Closed())
	{
		_window->Update();
		_inputHandler->ProcessInput();
	}
	return 0;
}

// Error Callback: Gets called whenever an error occurs within GLFW.
void Engine::Error_Callback(int error, const char * description)
{
	fprintf(stderr, "Error: %s\n", description);
}
