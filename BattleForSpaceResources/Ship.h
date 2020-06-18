//#ifndef BFSR_SHIP
//#define BFSR_SHIP

#include "CollisionObject.h"
#include "Mouse.h"
#include "Keyboard.h"

#pragma once
class Ship : public CollisionObject
{
public:
	vec3 speed;

	Ship(GLuint* texture, vec3 position, vec3 rotate, vec3 scale, vec4 color);
	Ship();
	Ship(Ship const& object);
	Ship& operator=(const Ship& object);

	void setSpeed(vec3 speed);

	virtual void update();
	virtual void render();

	~Ship();
};

//#endif