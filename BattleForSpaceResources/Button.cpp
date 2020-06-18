#include "Button.h"

AABB aabb;
string text;
int id;

Button::Button(int id, GLuint* texture, vec3 position, vec3 scale, vec4 color, string text)
: TextureObject(texture, position, vec3(0,0,0), scale, color)
{
	aabb = AABB(vec2(position.x, position.y), vec2(position.x + scale.x, position.y + scale.y));
	setOrigin(vec2(-scale.x/2.0, -scale.y / 2.0));

	this->id = id;
	this->text = text;
}

Button::Button(int id, Texture texture, vec3 position, vec4 color, string text)
: TextureObject(texture, position, vec3(0,0,0), color)
{
	aabb = AABB(vec2(position.x, position.y), vec2(position.x + scale.x, position.y + scale.y));
	setOrigin(vec2(-scale.x / 2.0, -scale.y / 2.0));

	this->id = id;
	this->text = text;
}

Button::Button()
: TextureObject()
{

}

void Button::update()
{

}

void Button::render()
{
	TextureObject::render();
}


Button::Button(Button const& other)
:TextureObject(other)
{
	this->aabb = other.aabb;
	this->text = other.text;
	this->id = other.id;
}

Button& Button::operator=(const Button& other)
{
	if (this != &other)
	{
		TextureObject::operator=(other);
		aabb = other.aabb;
		text = other.text;
		id = other.id;
	}
	return *this;
}


Button::~Button()
{
}
