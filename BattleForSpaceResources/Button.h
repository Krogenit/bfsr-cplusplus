#include "TextureObject.h"
#include "AABB.h"

#pragma once
class Button : public TextureObject
{
public:
	AABB aabb;
	string text;
	int id;

	Button(int id, GLuint* texture, vec3 position, vec3 scale, vec4 color, string text);
	Button(int id, Texture texture, vec3 position, vec4 color, string text);
	Button();
	Button(Button const& object);
	Button& operator=(const Button& other);

	void update();
	void render();

	~Button();
};

