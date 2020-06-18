#include "World.h"

TextureObject* background;
list<Ship>* ships;

World::World()
{
	CollisionObject::gravity = 0.002f;

	background = new TextureObject(TextureLoader::textures["background1"].texture, vec3(0, 0, 0), vec3(0, 0, 0), vec3(1920, 1080, 1), vec4(1, 1, 1, 1));

	ships = new list<Ship>;

	Ship ship = Ship(TextureLoader::textures["human_small0"].texture, vec3(100, 100, 0), vec3(0, 0, 0), vec3(64, 64, 1), vec4(1, 1, 1, 1));
	ship.setOrigin(vec2(-32, -32));
	ship.setRotationSpeed(2.0f);
	ship.setMass(2.0f);
	ship.setSpeed(vec3(5, 0, 0));

	ships->push_back(ship);

	//ship = new CollisionObject(TextureLoader::shipTexture, vec3(100, 100, 0), vec3(0,0,0), vec3(1,1,1), vec4(1,1,1,1));
}

void World::update()
{
	for (list<Ship>::iterator it = ships->begin(); it != ships->end(); it++)
	{
		it->update();
	}

}

void World::renderEntitys()
{
	for (list<Ship>::iterator it = ships->begin(); it != ships->end(); it++)
	{
		it->render();
	}
}

void World::renderAmbient()
{
	background->render();
}

void World::renderWorld()
{
	renderAmbient();
	renderEntitys();
}


void World::setBackgroundScale(float x, float y)
{
	background->scale.x = 1920 * x;
	background->scale.y = 1080 * y;
}

World::~World()
{
	delete background;
	delete ships;
}