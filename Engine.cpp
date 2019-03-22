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
	if (_initialized)
	{
		std::cout << "The engine was already initialized!";
		return 1;
	}

	// Create and Initialize a Window object.
	_window = new Window(WIDTH, HEIGHT, "Minecraft Magma Edition");
	if (!_window)
	{
		std::cout << "Failed to create a Window object." << std::endl;
		return -1;
	}

	int result = _window->Initialize();
	if (result)
	{
		std::cout << "Something went wrong during WINDOW initialization. Error: " << result << std::endl;
		return result;
	}

	// Create a Camera object.
	_camera = new Camera();
	if (!_camera)
	{
		std::cout << "Failed to create Camera object." << std::endl;
		return -4;
	}

	// Create an Input Handler object.
	_inputHandler = new InputHandler(_window->GetCurrentWindowRef(), *_camera);
	if (!_inputHandler)
	{
		std::cout << "Failed to create InputHandler object." << std::endl;
		return -5;
	}

	return 0;
}

// Main execution point.
int Engine::Run()
{
	// ===== SETUP ======
	Shader triangleShader = Shader("Resources/Shaders/Textured.vs", "Resources/Shaders/Textured.fs");
	Triangle cube = Triangle(&triangleShader);
	cube.Initialize();

	cube.AddTexture("Resources/Assets/texture_stone.png");
	// ==================

	// Game loop.
	while (!_window->Closed())
	{
		UpdateTime();
		
		_inputHandler->ProcessInput(_deltaTime);
		
		// create transformations
		glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);
		model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		projection = glm::perspective(glm::radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
		// retrieve the matrix uniform locations
		unsigned int modelLoc = glGetUniformLocation(triangleShader.ID, "model");
		unsigned int viewLoc = glGetUniformLocation(triangleShader.ID, "view");
		// pass them to the shaders (3 different ways)
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
		triangleShader.SetMat4("projection", projection);

		// ===== DRAWING ======
		_window->Clear();
		cube.Draw();
		_window->Update();
		// ====================		
	}

	return 0;
}

void Engine::UpdateTime()
{
	// per-frame time logic
	float currentFrame = (float)glfwGetTime();
	_deltaTime = currentFrame - _lastFrame;
	_lastFrame = currentFrame;
}

void Engine::Draw()
{

}

// Error Callback: Gets called whenever an error occurs within GLFW.
void Engine::Error_Callback(int error, const char * description)
{
	fprintf(stderr, "Error: %s\n", description);
}
