#include "Engine.h"

const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

// camera
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

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

	if (_inputHandler)
	{
		delete _inputHandler;
		_inputHandler = 0;
	}

	// Destroy singleton instances since (this) is the last possible accessor class.
	TextureLoader::Instance().~TextureLoader();
	Camera::Instance().~Camera();
	_camera = 0;

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
	_window = new Window(SCR_WIDTH, SCR_HEIGHT, "Minecraft Magma Edition");
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

	// Store a pointer to the camera.
	_camera = &Camera::Instance();

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
	Shader cubeShader = Shader("Resources/Shaders/Textured.vs", "Resources/Shaders/Textured.fs");
	Cube cube = Cube(&cubeShader);
	cube.Initialize();

	const int chunkSize = 16 * 16 * 16;

	glm::vec3 cubePositions[chunkSize];

	for (int y = 0; y < 16; y++)
	{
		for (int z = 0; z < 16; z++)
		{
			for (int x = 0; x < 16; x++)
			{
				cubePositions[x + z * 16 + y * 16 * 16] = glm::vec3(x, y, z);
			}
		}
	}


	cube.AddTexture("Resources/Assets/texture_stone.png");

	cubeShader.SetVec3("viewPos", Camera::Instance().position);

	// Game loop.
	while (!_window->Closed())
	{
		UpdateTime();
		
		_inputHandler->ProcessInput(_deltaTime);
		
		// ===== DRAWING ======
		_window->Clear();

		// pass projection matrix to shader (note that in this case it could change every frame)
		glm::mat4 projection = glm::perspective(glm::radians(Camera::Instance().zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		cubeShader.SetMat4("projection", projection);

		// camera/view transformation
		glm::mat4 view = Camera::Instance().GetViewMatrix();
		cubeShader.SetMat4("view", view);

		for (unsigned int i = 0; i < chunkSize; i++)
		{
			// calculate the model matrix for each object and pass it to shader before drawing
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, cubePositions[i]);
			cubeShader.SetMat4("model", model);

			cube.Draw();
		}
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
