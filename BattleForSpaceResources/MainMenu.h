#include "Gui.h"
#include "TextureLoader.h"
#pragma once
class Core;
class MainMenu : public Gui
{
public:
	Core* core;
	TextureObject bfsrText;

	MainMenu(Core* core, int width, int height);
	MainMenu();

	void onButtonLeftClick(Button b);

	void resize(int width, int height);
	void update();
	void render();

	~MainMenu();
};

