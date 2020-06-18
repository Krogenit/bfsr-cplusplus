#include "MainMenu.h"
#include "Core.h"

TextureObject bfsrText;
Core* core;

MainMenu::MainMenu(Core* core, int width, int height)
: Gui(width, height)
{
	this->core = core;

	bfsrText = TextureObject(TextureLoader::textures["bfsr_text2"].texture, vec3(width / 2, height / 2 - 200, 0),
		vec3(0,0,0),
		vec3(900, 100, 0),
		vec4(1, 1, 1, 1));
	bfsrText.setOrigin(vec2(-bfsrText.scale.x/2.0, -bfsrText.scale.y / 2.0));

	buttons = new std::list<Button>;

	Button b1 = Button(0, TextureLoader::textures["gui_buttonBase"], vec3(width / 2, height / 2 - 50, 0),
		vec4(1, 1, 1, 1), "Одиночная игра");
	Button b2 = Button(1, TextureLoader::textures["gui_buttonBase"], vec3(width / 2, height / 2 - 0, 0),
		vec4(1, 1, 1, 1), "Сетевая игра");
	Button b3 = Button(2, TextureLoader::textures["gui_buttonBase"], vec3(width / 2, height / 2 + 50, 0),
		vec4(1, 1, 1, 1), "Настройки");
	Button b4 = Button(3, TextureLoader::textures["gui_buttonBase"], vec3(width / 2, height / 2 + 100, 0),
		vec4(1, 1, 1, 1), "Выход");

	buttons->push_back(b1);
	buttons->push_back(b2);
	buttons->push_back(b3);
	buttons->push_back(b4);
}

MainMenu::MainMenu()
:Gui()
{

}

void MainMenu::onButtonLeftClick(Button b)
{
	switch (b.id)
	{
	case 0:
		core->startMultiplayer();
		return;
	case 1:
		return;
	case 2:
		return;
	case 3:
		return;
	}
}

void MainMenu::update()
{
	Gui::update();
}

void MainMenu::render()
{
	bfsrText.render();
	Gui::render();
}

void MainMenu::resize(int width, int height)
{
	int dx = width - this->width;
	int dy = height - this->height;

	bfsrText.position = vec3(width / 2, height / 2 - 400, 0);
	Gui::resize(width, height);
}


MainMenu::~MainMenu()
{
}
