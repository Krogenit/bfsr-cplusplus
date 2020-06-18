#include "Ship.h"
#include "TextureLoader.h"
#include "Keyboard.h"
#include <list>

#pragma once
class World
{
public:
	TextureObject* background;
	list<Ship>* ships;

	World();
	~World();
	void setBackgroundScale(float x, float y);

	void update();

	void renderEntitys();
	void renderWorld();
	void renderAmbient();
};