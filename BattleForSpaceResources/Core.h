#include "Mouse.h"
#include "PathHelper.h"
#include "World.h"
#include "Gui.h"
#include "MainMenu.h"

#pragma once
class Core
{
public:
	int screenWidth, screenHeight;

	World *world;
	bool isDebug, isRemote;

	Gui* currentGui;

	Core(GLFWwindow* window, int width, int height);
	void startSingleplayer();
	void startMultiplayer();
	void setCurrentGui(Gui* gui);
	void resize(int width, int height);
	void update();
	void render();
	void updateThread();
};