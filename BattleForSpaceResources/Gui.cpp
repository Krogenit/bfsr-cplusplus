#include "Gui.h"

int width, height;
list<Button>* buttons;

Gui::Gui(int width, int height)
{
	buttons = NULL;
	this->width = width;
	this->height = height;
}

Gui::Gui()
{
	buttons = NULL;
}

void Gui::onKey()
{

}

void Gui::onButtonLeftClick(Button b)
{

}

void Gui::onButtonRightClick(Button b)
{

}

void Gui::onLeftClicked()
{
	float x = Mouse::mouseX;
	float y = Mouse::mouseY;
	for (std::list<Button>::iterator it = buttons->begin(); it != buttons->end(); it++)
		if (it->aabb.isIntersects(vec2(x, y)))
			onButtonLeftClick(*it);
}

void Gui::onRightClicked()
{
	float x = Mouse::mouseX;
	float y = Mouse::mouseY;
	for (std::list<Button>::iterator it = buttons->begin(); it != buttons->end(); it++)
		if (it->aabb.isIntersects(vec2(x, y)))
			onButtonRightClick(*it);
}

void Gui::update()
{
	if (Mouse::isLeftClicked())
		onLeftClicked();
	if (Mouse::isRightClicked())
		onRightClicked();
}

void Gui::render()
{
	for (std::list<Button>::iterator it = buttons->begin(); it != buttons->end(); it++)
		it->render();
}

void Gui::resize(int width, int height)
{
	int dx = width - this->width;
	int dy = height - this->height;

	for (std::list<Button>::iterator it = buttons->begin(); it != buttons->end(); it++)
	{
		//it->position.x = 
	}
}

Gui::~Gui()
{
}
