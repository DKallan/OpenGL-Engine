#include "Engine.h"

int main()
{
	Engine* engine = new Engine();

	// Initialize the engine.
	int result = engine->Initialize();
	if (result)
	{
		std::cout << "Something went wrong during ENGINE initialization. Error: " << result << std::endl;
		
		// Clean up.
		delete engine;
		engine = 0;
		
		// Exit.
		return result;
	}

	engine->Run();

	// Clean up.
	delete engine;
	engine = 0;

	return 0;
}