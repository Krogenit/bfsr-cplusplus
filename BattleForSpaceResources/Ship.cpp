#include "Ship.h"

vec3 speed;

Ship::Ship(GLuint* texture, vec3 position, vec3 rotate, vec3 scale, vec4 color)
: CollisionObject(texture, position, rotate, scale, color)
{

}

Ship::Ship()
{
}


Ship::Ship(Ship const& object)
: CollisionObject(object)
{
	speed = vec3(object.speed);
}

Ship& Ship::operator=(const Ship& other)
{
	if (this != &other)
	{
		CollisionObject::operator=(other);
		speed = vec3(other.speed);
	}
	return *this;
}

void Ship::update()
{
	rotateToVector(vec2(Mouse::mouseX, Mouse::mouseY));

	if (*Keyboard::KEY_W)
		moveForward(speed.x);

	CollisionObject::update();
}

void Ship::render()
{
	CollisionObject::render();
}

void Ship::setSpeed(vec3 speed)
{
	this->speed = speed;
}

Ship::~Ship()
{
}
