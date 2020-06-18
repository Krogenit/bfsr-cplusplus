#include "TextureObject.h"
#include "Button.h"
#include <list>
#include "Mouse.h"

#pragma once
class Gui : public TextureObject
{
public:

	int width, height;
	std::list<Button>* buttons;

	Gui(int width, int height);
	Gui();

	virtual void resize(int width, int height);
	virtual void update();
	virtual void render();

	virtual void onButtonLeftClick(Button b);
	virtual void onButtonRightClick(Button b);

	virtual void onKey();
	virtual void onLeftClicked();
	virtual void onRightClicked();

	~Gui();
};

