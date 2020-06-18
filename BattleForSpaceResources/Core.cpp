#include "Core.h"

int screenWidth, screenHeight;

bool isDebug = true, isRemote;
World* world;

Gui* currentGui;

Core::Core(GLFWwindow* window, int width, int height)
{
	isRemote = true;
	PathHelper::init(isDebug);
	TextureLoader::loadTextures();
	Keyboard::registerKeys();
	Mouse::registerMouse(window);
		
	currentGui = new MainMenu(this, width, height);
	world = NULL;

	//world = new World();
}

void Core::startSingleplayer()
{
	world = new World();
}

void Core::startMultiplayer()
{

}

void Core::setCurrentGui(Gui* gui)
{
	this->currentGui = gui;
}

void Core::update()
{
	Mouse::updateState(true);

	if (world != NULL)
		world->update();
	if (currentGui)
		currentGui->update();

	Mouse::updateState(false);
}

void Core::render()
{
	if (world != NULL)
		world->renderWorld();
	if (currentGui)
		currentGui->render();
}

void Core::resize(int width, int height)
{
	screenWidth = width;
	screenHeight = height;
	if (world != NULL)
	world->setBackgroundScale(width / 1920.0, height / 1080.0);
}

void Core::updateThread()
{
	double MS_PER_UPDATE = 0.01666666;
	double previous = glfwGetTime();
	double lag = 0.0;
	while (true)
	{
		double current = glfwGetTime();
		double elapsed = current - previous;
		previous = current;
		lag += elapsed;
		while (lag >= MS_PER_UPDATE)
		{
			update();
			lag -= MS_PER_UPDATE;
		}
	}
}